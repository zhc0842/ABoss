/*
 * �����м����ƽ̨��Χ����ͷ�ļ� (C++���Ա�׼�ӿ��ļ�)
 * FixApi.h   2007��4�� ����
 * ��FixApi.lib FixApi.dllһ���ṩ��
 * �ʺ�ABOSS2.0��Χ���롣 
*/

#if !defined(AFX_FIXAPI_H__VER2001__INCLUDED_)
#define AFX_FIXAPI_H__VER2001__INCLUDED_

#ifdef USE_FIXAPI_CLASS
    #include <FixApi/FixConn.h>
#endif

#ifndef FIX_API_EXPORT
    #define FIX_API_EXPORT  __declspec(dllexport)        
#endif

//���Ӿ��
#define HANDLE_CONN     long

//�Ự���
#define HANDLE_SESSION  long

//������
#define HANDLE_SVC      long

/*  ��������: Fix_Initialize
              �������ӿڿ��ʼ����ֻ�е���һ�ξͿ��ԣ����ܶ�ε��á�
    ��������: 
              ����True��ʾ��ʼ���ɹ���False��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_Initialize();
    BOOL FIX_API_EXPORT Fix_SetAppInfo( const char *pszAppName, const char *pszVer );
/*  ��������: Fix_Uninitialize
              �������ӿڿ�ж�ء�ֻ�е���һ�ξͿ��ԣ����ܶ�ε��á�
    ��������: 
              ����True��ʾ��ʼ���ɹ���False��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_Uninitialize();

/*
  ��������: Fix_SetDefaultInfo
            ����ÿ��ҵ�������ȱʡ��ͷ��Ϣ
  ����˵��: 
            pszUser     -- [in] ϵͳҪ��Ĺ�Ա����(��λ���ַ���)��
            pszWTFS     -- [in] ί�з�ʽ��
            pszFBDM     -- [in] ����Ӫҵ���Ĵ�����Ϣ(��λ���ַ���)
            pszDestFBDM -- [in] Ŀ��Ӫҵ���Ĵ�����Ϣ(��λ���ַ���)

  ��������: 
            ϵͳ��������ΪHANDLE_CONN�����Ӿ�����������ʧ���򷵻�0; �ɹ���Ϊ0;
*/
    FIX_API_EXPORT BOOL Fix_SetDefaultInfo( const char *pszUser, const char *pszWTFS, const char *pszFBDM, const char *pszDestFBDM );

/*
 *	��������:Fix_SetDefaultQYBM
    ����ȱʡ���������
 */
    FIX_API_EXPORT BOOL Fix_SetDefaultQYBM( const char *pszQYBM );
/*
  ��������: Fix_Connect
            ���ӵ������м����������
  ����˵��: 
            pszAddr  -- [in] ΪҪ���ӵķ�������ַ; ��ʽΪ: "ip��ַ@�˿�/tcp"
            pszUser  -- [in]  ͨ���û�����; �ɿͻ��ṩ��
            pszPwd   -- [in] ͨ���û�������; �ɿͻ��ṩ��
            nTimeOut -- [in] ���ӳ�ʱ��ʱ�䡣��λΪ�롣

  ��������: 
            ϵͳ��������ΪHANDLE_CONN�����Ӿ�����������ʧ���򷵻�0; �ɹ���Ϊ0;
*/
    FIX_API_EXPORT HANDLE_CONN  Fix_Connect( const char *pszAddr, const char *pszUser, const char *pszPwd, long nTimeOut );
    FIX_API_EXPORT BOOL Fix_AddBackupSvrAddr( const char *pszAddr );
/*
  ��������: Fix_Close
            �붥���м�����ӹرա�
  ����˵��: 
            conn -- [in] ����ΪHANDLE_CONN�����Ӿ�����þ����Fix_Connect���ɵġ�
  ��������: 
            ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_Close( HANDLE_CONN conn );

/*
  ��������: Fix_AllocateSession
            ����һ�����Ӿ������һ���Ự������������ݽ�����
            ���û��Լ���Ӧ�ò�ͨ������Fix_AllocateSession��������Ķ���������û��Լ�����Fix_ReleaseSession���ͷš�
            ��֮�򲻱�Ҫ��ԭ������ѭ��˭����˭�ͷš��������Ϳ���ȷ���ڴ治й¶��
  ����˵��: 
            conn -- [in] ����ΪHANDLE_CONN�����Ӿ�����þ����Fix_Connect���ɵġ�
  ��������: 
            ����ֵ����ΪHANDLE_SESSION�ĻỰ�����������ֵΪ�ձ�ʾ�������ʧ�ܡ������ʾ�ɹ���
*/
    FIX_API_EXPORT HANDLE_SESSION Fix_AllocateSession( HANDLE_CONN conn );

/*
  ��������: Fix_ReleaseSession
            �ͷŻỰ�����
  ����˵��: 
            sess -- [in] ����ΪHANDLE_SESSION�ĻỰ����
  ��������: 
            ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_ReleaseSession( HANDLE_SESSION sess );

/*
  ��������: Fix_SetTimeOut
            ���ûỰ�����ĳ�ʱʱ�䡣
  ����˵��: 
            conn    -- [in] ����ΪHANDLE_CONN�����Ӿ�����þ����Fix_Connect���ɵġ�
            timeout -- [in] ҵ��Ӧ��ʱʱ�䣻��λΪ�룬ϵͳĬ��Ϊ30�롣
  ��������: 
            ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetTimeOut( HANDLE_SESSION sess, long timeout );

/*
   ��������: Fix_SetWTFS
             ���ûỰ��ί�з�ʽ.(������Fix_CreateHead����֮ǰ����)
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             val  -- [in] �ַ������͡����ڱ�ʾ�ͻ��Ľ��뷽ʽ��
                          ����绰ί�У��ſ�ί�У�������ί�еȡ�
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetWTFS( HANDLE_SESSION sess, const char *val );

/*
   ��������: Fix_SetFBDM
             ���ûỰ�ķ���Ӫҵ������.(������Fix_CreateHead����֮ǰ����)
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             val  -- [in] �ַ������͡����ڱ�ʾ�ͻ�ҵ������Ӫҵ����,��������λ��Ӫҵ������;
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetFBDM( HANDLE_SESSION sess, const char *val );

/*
   ��������: Fix_SetFBDM
             ���ûỰ�ķ���Ӫҵ������.(������Fix_CreateHead����֮ǰ����)
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             val  -- [in] �ַ������͡����ڱ�ʾ�ͻ�ҵ�񵽴��Ŀ���Ӫҵ����,��������λ��Ӫҵ������;
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetDestFBDM( HANDLE_SESSION sess, const char *val );

/*
   ��������: Fix_SetNode
             ���ûỰ��ҵ�����Ľڵ���Ϣ.(������Fix_CreateHead����֮ǰ����)
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             val  -- [in] �ַ������͡�һ���ǿͻ�������Ϣ��IP��ַ��
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetNode( HANDLE_SESSION sess, const char *val );

/*
   ��������: Fix_SetGYDM
            ���ûỰ��ҵ�����Ĺ�Ա������Ϣ.(������Fix_CreateHead����֮ǰ����)
   ����˵��: sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             val  -- [in] �ַ������͡���һЩ��̨����ҵ����Ҫ�õ���Ա��Ϣ������֤��
   ��������: ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetGYDM( HANDLE_SESSION sess, const char *val );

/*
   ��������: Fix_CreateHead
             ���ûỰ��ҵ���ܺ�.����Ĺ��ܺŵĶ�������ա�����������ҵ��ӿ��ĵ�����
   ����˵��: 
             sess  -- [in]  ����ΪHANDLE_SESSION�ĻỰ�����
             nFunc -- [in]  ���͡���Ϊϵͳ�ṩ��ҵ���ܺš�
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_CreateHead( HANDLE_SESSION sess, long nFunc );
    BOOL FIX_API_EXPORT Fix_CreateHead( HANDLE_SESSION sess, const char *pszFunc );
    BOOL FIX_API_EXPORT Fix_CreateReq( HANDLE_SESSION sess, long nFunc );
/*
   ��������: Fix_SetItem
             ���øûỰҪ���͸��м����ҵ������������� �����Ӧ�������ݡ�
             ע:( ����Ӧ��������ֻ�����һЩ�м��ҵ����Ҫ�������������������ʹ�á�
                  ������Ҫ��ͨ��ע�����ʵ��; һ�������²�ʹ�ø÷�ʽ���롣)
   ����˵��: 
             sess -- [in]  ����ΪHANDLE_SESSION�ĻỰ�����
             id   -- [in]  �������tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             val  -- [in]  �ַ�������;��Ӧ��id��ҵ�����ݡ�
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetItem( HANDLE_SESSION sess, long id, const char *val );
    BOOL FIX_API_EXPORT Fix_SetString( HANDLE_SESSION sess, long id, const char *val );
    BOOL FIX_API_EXPORT Fix_SetLong( HANDLE_SESSION sess, long id, long val );
    BOOL FIX_API_EXPORT Fix_SetDouble( HANDLE_SESSION sess, long id, double val );

/*
   ��������: Fix_SetItem
             ���øûỰҪ���͸��м����ҵ������������� �����Ӧ�������ݡ�  
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             id   -- [in] �������tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             val  -- [in] ����;��Ӧ��id��ҵ�����ݡ�
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetItem( HANDLE_SESSION sess, long id, long val );

/*
   ��������: Fix_SetItem
             ���øûỰҪ���͸��м����ҵ������������� �����Ӧ�������ݡ�  
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             id   -- [in] �������tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             val  -- [in] ��������;��Ӧ��id��ҵ�����ݡ�
   ��������: 
             ����ֵΪTrue��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_SetItem( HANDLE_SESSION sess, long id, double val );

/*
   ��������: Fix_Run
             �ύҵ�����ݣ����ȴ�ȫ����ҵ�������ء�  
   ����˵��: 
             sess -- [in]  ����ΪHANDLE_SESSION�ĻỰ�����

   ��������: 
             ����ֵΪTrue��ʾ����ҵ����ɹ�; FALSE��ʾʧ��,���ʧ���Ǳ�ʾҵ��ͨ���ϵ�ʧ�ܣ�
             ʧ�ܺ󣬿���ͨ��Fix_GetCodeȡ��������(�ض���һ������)��ͨ��Fix_GetErrMsgȡ���������Ϣ��
*/
    BOOL FIX_API_EXPORT Fix_Run( HANDLE_SESSION sess );

/*
   ��������: Fix_Cancel
             ֱ�ӷ����ȴ�ҵ���Ӧ�����ݡ�(��ͬ����ʽ��ʹ��)
   ����˵��: 
             sess -- [in]  ����ΪHANDLE_SESSION�ĻỰ�����

   ��������: 
             ����ֵΪTRUE��ʾ�ɹ�; FALSE��ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_Cancel( HANDLE_SESSION sess );


/*
   ��������: Fix_AsyncRun
             �첽�ύҵ�����ݣ����ȴ���ȫ����ҵ�������ء�
             �ͺ���Fix_IsReplyed���ʹ��.
   ����˵��: 
             sess -- [in]  ����ΪHANDLE_SESSION�ĻỰ�����

   ��������: 
             ����ֵΪTrue��ʾ����ҵ����ɹ�; FALSE��ʾʧ��,���ʧ���Ǳ�ʾҵ��ͨ���ϵ�ʧ�ܣ�
             ʧ�ܺ󣬿���ͨ��Fix_GetCodeȡ��������(�ض���һ������)��ͨ��Fix_GetErrMsgȡ���������Ϣ��
*/
    BOOL FIX_API_EXPORT Fix_AsyncRun( HANDLE_SESSION sess );

/*
   ��������: Fix_IsReplyed
             �첽�ύҵ�����ݺ󣬼�������Ƿ�ȫ�����ء�
   ����˵��: 
             sess -- [in]  ����ΪHANDLE_SESSION�ĻỰ�����
             nMSec [in/option] ָ���ȴ���ʱ�䣬Ĭ�ϲ��ȴ�����λΪ���롣

   ��������: 
             ����ֵΪTrue��ʾӦ������ȫ������; FALSE��ʾ��Ҫ�����ȴ���
*/
    BOOL FIX_API_EXPORT Fix_IsReplyed( HANDLE_SESSION sess, long nMSec=-1 );

/*
   ��������: Fix_GetCode
             ��ȡҵ���ύʧ�ܵĴ�����롣  
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ���ظ�������
*/
    long FIX_API_EXPORT Fix_GetCode( HANDLE_SESSION sess );

/*
   ��������: Fix_GetErrMsg
             ��ȡҵ���ύʧ�ܵĴ�����Ϣ��  
   ����˵��: 
             sess   -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             out    -- [in/out] �������������Ϣ���ַ���.
             outlen -- [in] ����out�������Ĵ�С.
   ��������: 
             ���ش�����Ϣ�ַ�����
*/
    char FIX_API_EXPORT *Fix_GetErrMsg( HANDLE_SESSION sess, char *out, int outlen );

/*
   ��������: Fix_GetCount
             ��ȡ�м�����ص�ҵ��Ӧ�����ݵ�������  
   ����˵��: 
             sess -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ������������
*/
    long FIX_API_EXPORT Fix_GetCount( HANDLE_SESSION sess );

/*
   ��������: Fix_GetItem
             1�����м���ķ��ؽ������ָ�����ж�ȡҵ��Ӧ�����ݡ�
             2�������Ƕ�ȡ�м�������ҵ������
   ����˵��: 
             sess   -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             id     -- [in] ָ�����tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             out    -- [in/out] �������ҵ����Ϣ���ַ���.
             outlen -- [in] ָ��out�������Ĵ�С.
             row    -- [in][option] ָ���������ݽ�����е�����(��������ֵ��0��ʼ).������������ֵ��
                       ��ʾ��ȡ��һ�е����ݡ�
   ��������: 
             ����ָ���еĵ��ַ������ݡ�
*/
    char FIX_API_EXPORT *Fix_GetItem( HANDLE_SESSION sess, long id, char *out, int outlen, long row = -1 );
    
/*
   ��������: Fix_GetLong
             1�����м���ķ��ؽ������ָ�����ж�ȡҵ��Ӧ�����ݡ�
             2�������Ƕ�ȡ�м�������ҵ������
   ����˵��: 
             sess   -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             id     -- [in] ָ�����tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             row    -- [in][option] ָ���������ݽ�����е�����(��������ֵ��0��ʼ).������������ֵ��
                       ��ʾ��ȡ��һ�е����ݡ�
   ��������: 
             ����ָ���е��������ݡ�
*/
    long FIX_API_EXPORT Fix_GetLong( HANDLE_SESSION sess, long id, long row = -1 );
  
/*
   ��������: Fix_GetDouble
             1�����м���ķ��ؽ������ָ�����ж�ȡҵ��Ӧ�����ݡ�
             2�������Ƕ�ȡ�м�������ҵ������
   ����˵��: 
             sess   -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             id     -- [in] ָ�����tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             row    -- [in][option] ָ���������ݽ�����е�����(��������ֵ��0��ʼ).������������ֵ��
                       ��ʾ��ȡ��һ�е����ݡ�
   ��������: 
             ����ָ���еĸ������ݡ�
*/
    double FIX_API_EXPORT Fix_GetDouble( HANDLE_SESSION sess, long id, long row = -1 );

/*
   ��������: Fix_HaveItem
             1������м���ķ��ؽ������ָ�������Ƿ���ָ����
             2�����߼���м�������ҵ�������Ƿ���ָ����
   ����˵��: 
             sess   -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             id     -- [in] ָ�����tagֵ������Ķ���ֵ��ο�������������ҵ��ӿ��ĵ�����
             row    -- [in][option] ָ���������ݽ�����е�����(��������ֵ��0��ʼ).������������ֵ��
                       ��ʾ��ȡ��һ�е����ݡ�
   ��������: 
             ����True��ʾ,����ָ���������ݣ�����û�С�
*/
    BOOL FIX_API_EXPORT Fix_HaveItem( HANDLE_SESSION sess, long id, long row = -1 );

/*
   ��������: Fix_UploadFile
             �ļ��ϴ�����.
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             pszName     -- [in] ָ���ϴ��ļ��ļ�ơ�
                                 (�ļ�����ɺ�̨ϵͳ�ṩ�����Ըò���һ����Ϊ�����õ�ѡ��)
             pszFileName -- [in] ����Ҫ�ϴ����ļ�·����                       
   ��������: 
             ����True��ʾ,�ļ��ϴ��ɹ��������ʾʧ�ܡ�
             ʧ��ԭ�����ͨ�� Fix_ErrMsg����,��ȡʧ�ܵ�ԭ��
*/
    BOOL FIX_API_EXPORT Fix_UploadFile(  HANDLE_SESSION sess, const char *pszName, const char *pszFileName );

/*
   ��������: Fix_DownloadFile
             �ļ��´�����.
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
             pszName     -- [in] ָ�������ļ��ļ�ơ�
                                (�ļ�����ɺ�̨ϵͳ�ṩ�����Ըò���һ����Ϊ�����õ�ѡ��)
             pszFileName -- [in] Ҫ���ص����ص��ļ�·����
   ��������: 
             ����True��ʾ,�ļ����سɹ��������ʾʧ�ܡ�
             ʧ��ԭ�����ͨ�� Fix_ErrMsg����,��ȡʧ�ܵ�ԭ��
*/
    BOOL FIX_API_EXPORT Fix_DownloadFile(  HANDLE_SESSION sess, const char *pszName, const char *pszFileName );



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
/*  ����������Ҫ�����м�������ҵ������ʱ�����������º����������ݵĽ�����
*/

/*
   ��������: Fix_RegisterSvc
             ����ע�ắ�������ڴ����м�������ҵ������
   ����˵��: 
             conn         -- [in] ����ΪHANDLE_CONN�����Ӿ����
             func         -- [in] ���ͣ�ָ���ķ������ơ�
             name         -- [in] �ַ������ͣ���ʾ�÷�������ơ�
             pFunc        -- [in] ָ���Ļص�����ָ�롣
                                  �ص������Ĵ��θ�ʽ: bool CallBack( HANDLE_CONN conn, HANDLE_SVC svc, HANDLE_SESSION sess );
             pszCondition -- [in] ָ�����������������������з����ҵ��Ҫ��ָ��ֻ����ĳ�����е�ҵ��
                                  ��ֻ�Ǵ����ָ���������ĵĵ�ҵ��
   ��������: 
             ����һ�����һ�����Ӿ����Ψһ�ķ�������
             �������ֵΪNULL,��ʾ����ע��ʧ��; �ɹ���ΪNULL��
*/
    HANDLE_SVC FIX_API_EXPORT Fix_RegisterSvc( HANDLE_CONN conn, long func, const char *name, void *pFunc, const char *pszCondition );

/*
   ��������: Fix_UnRegisterSvc
             ����ע��������
   ����˵��: 
             conn         -- [in] ����ΪHANDLE_CONN�����Ӿ����
             svc          -- [in] ָ���������Ѿ�ע��ķ�����롣
   ��������: 
             ����True��ʾ�ɹ��������ʾʧ�ܡ�
*/

    BOOL FIX_API_EXPORT Fix_UnRegisterSvc( HANDLE_CONN conn, HANDLE_SVC svc );

/*
   ��������: Fix_CreateAnswer
             ��������Ӧ������;���ڵ��е�����Ӧ��
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ����True��ʾ�ɹ��������ʾʧ�ܡ�
*/

    BOOL FIX_API_EXPORT Fix_CreateAnswer( HANDLE_SESSION sess );

/*
   ��������: Fix_CreateAnswerMul
             ��������Ӧ������;���ڶ��е�����Ӧ�𡣱����Fix_CreateNextAnswer��Fix_CreateEndMark���ʹ�á�
             ������Բ���Sample2�Ĵ��롣
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ����True��ʾ�ɹ��������ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_CreateAnswerMul( HANDLE_SESSION sess );

/*
   ��������: Fix_CreateNextAnswer
             ��������Ӧ������;�ڶ��е�����Ӧ�𡣴�����һ����Ӧ�����ݡ�
             ������Բ���Sample2�Ĵ��롣
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ����True��ʾ�ɹ��������ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_CreateNextAnswer( HANDLE_SESSION sess );

/*
   ��������: Fix_CreateEndMark
             ��������Ӧ������;�ڶ��е�����Ӧ�𡣴�������Ӧ�����ݡ�
             ������Բ���Sample2�Ĵ��롣
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ����True��ʾ�ɹ��������ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_CreateEndMark( HANDLE_SESSION sess );

/*
   ��������: Fix_Write
             ����Ӧ�����ݡ�
             ������Բ���Sample2�Ĵ��롣
   ����˵��: 
             sess        -- [in] ����ΪHANDLE_SESSION�ĻỰ�����
   ��������: 
             ����True��ʾ�ɹ��������ʾʧ�ܡ�
*/
    BOOL FIX_API_EXPORT Fix_Write( HANDLE_SESSION sess );

//�򵥼��ܺ���(�û��������)
    char FIX_API_EXPORT *Fix_Encode( char *pData );

/*
   ��������: Fix_GetToken
             ȡ�����ڵ������ַ���(��ѡ�����̨ϵͳ�����й�)
*/

    char FIX_API_EXPORT *Fix_GetToken( HANDLE_SESSION sess, char *out, int outlen );
/*
   ��������: Fix_SetToken
             ���ûỰ������(��ѡ�����̨ϵͳ�����й�)
*/
    BOOL FIX_API_EXPORT Fix_SetToken( HANDLE_SESSION sess, const char *val );


#endif
