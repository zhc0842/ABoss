// Test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "blsdef_3rd.h"
#include "FixApi.h"

int main()
{
	//Fix_Connect
	HANDLE_CONN 
	return 0;
}

void CTestApiDlg::OnNew() 
{
    if( m_Conn )
    {
        Fix_Close( m_Conn );
        m_Conn = NULL;
    }

    CString sAddr;
    UpdateData();
    GetDlgItem( IDC_EDIT_ADDR )->GetWindowText( sAddr );

    m_Conn = Fix_Connect( sAddr, "", "", 1000 );
    if( m_Conn == NULL )
    {
        CString sNote;
        sNote.Format( "Connect Svr fail!\n%s", sAddr );
        AfxMessageBox( sNote );
        return;
    }
	
}

void CTestApiDlg::OnRun() 
{
	if( m_Conn == NULL )
        return;

    char out[512];
    HANDLE_SESSION sess;
    sess = Fix_AllocateSession( m_Conn );
    Fix_CreateHead( sess, FUN_CUSTOM_CHKTRDPWD );
    Fix_SetItem( sess, FID_KHH, "100100000001" );
    if( Fix_Run(sess) )
    {        
        Fix_GetLong( sess, FID_CODE );
        Fix_GetItem( sess, FID_MESSAGE, out, sizeof(out) );        
    }
    else
    {
        Fix_GetErrMsg( sess, out, sizeof(out) );
    }
    AfxMessageBox( out );
    Fix_ReleaseSession( sess );
}

void CTestApiDlg::OnQuery() 
{
    if( m_Conn == NULL )
        return;
    int i;
    char out[512];
    HANDLE_SESSION sess;
    sess = Fix_AllocateSession( m_Conn );
    Fix_CreateHead( sess, FUN_PARAM_LIST_USERROLE );
    Fix_SetItem( sess, FID_LOGINID, "99999998" );
    Fix_SetItem( sess, FID_DLSF, (long)1 );
    Fix_SetItem( sess, FID_QXLB, (long)1 );
    Fix_SetItem( sess, FID_SHBZ, (long)1 );
    if( Fix_Run( sess ) )
    {
        CString sNote;
        for( i = 0; i < Fix_GetCount(sess); i++ )
        {
            Fix_GetItem( sess, FID_JSDM, out, sizeof(out), i );
            sNote += out;
            sNote += "\n";
        }
        AfxMessageBox( sNote );
    }
    else
    {
        Fix_GetErrMsg( sess, out, sizeof(out) );
    }
    Fix_ReleaseSession( sess );	
}
bool CallBack( HANDLE_CONN conn, HANDLE_SESSION sess, long nSvc, long nRec )
{
    /* 
    //  如果系统要求文件上传或下载直接在此加入文件传输函数
    //  但是必须重新分配会话句柄HANDLE_SESSION
    //  HANDLE_SESSION sess2;

        sess2 = Fix_AllocateSession( m_Conn );
        if( Fix_DownloadFile( sess2, "abc", "c:\\v2.dbf" ) == false )
        {        
            char out[512];
            int outlen = 512;
            Fix_GetErrMsg( sess, out, outlen );          
            AfxMessageBox( out );
        }
        Fix_ReleaseSession( sess2 );  
        // 注意: 这里必须释放sess2对象。
    */

    // 多行应答
    Fix_CreateAnswerMul( sess );
    for( int i = 0; i < 10; i++ )
    {
        CString sNote;
        sNote.Format(" MYNote:%li", i );
        Fix_SetItem( sess, FID_CODE, (long)1 );
        Fix_SetItem( sess, FID_MESSAGE, sNote );
        Fix_Write( sess );
        Fix_CreateNextAnswer( sess );
    }    
    Fix_CreateEndMark( sess );
    Fix_Write( sess );
    
    // 注意：这里没有必要调用Fix_ReleaseSession函数释放sess.
    // 多行应答结束

    /*
    /* 单行应答
    Fix_CreateAnswer( sess );    
    CString sNote;
    sNote.Format(" MYNote:%li", i );
    Fix_SetItem( sess, FID_CODE, (long)1 );
    Fix_SetItem( sess, FID_MESSAGE, sNote );
    Fix_Write( sess );    
    /* 单行应答结束
    */

    return true;
}
void CTestApiDlg::OnClose() 
{
    if( m_Conn == NULL )
        return;
    Fix_Close( m_Conn );
    m_Conn = NULL;    
}

void CTestApiDlg::OnInit() 
{
    //只能调用一次
	Fix_Initialize();
    GetDlgItem( IDC_INIT )->EnableWindow( FALSE );
    GetDlgItem( IDC_NEW )->EnableWindow( TRUE );
}

void CTestApiDlg::OnUninit() 
{
    //只能调用一次
	Fix_Uninitialize();
    GetDlgItem( IDC_INIT )->EnableWindow( FALSE );
	GetDlgItem( IDC_UNINIT )->EnableWindow( FALSE );
    GetDlgItem( IDC_NEW )->EnableWindow( FALSE );
    GetDlgItem( IDC_CLOSE )->EnableWindow( FALSE );
    GetDlgItem( IDC_RUN )->EnableWindow( FALSE );
    GetDlgItem( IDC_QUERY )->EnableWindow( FALSE );
    GetDlgItem( IDC_FILE )->EnableWindow( FALSE );
    GetDlgItem( IDC_REGSVC )->EnableWindow( FALSE );
}