

/*******************************************************************************
 PROJECT   :
 SUBSYSTEM :
 MODULE    :
 OWNER     :
*******************************************************************************/

#include "msp_errno.h"
#include <dms.h>
#include "dms_core.h"
#include "vos.h"


#define THIS_FILE_ID LMSP_FILE_ID_DMS_ACM_AT_TX_C

DMS_STATIC_BUF_STRU stDmsStaticBufInfo ;

#if (VOS_WIN32== VOS_OS_VER)

VOS_UINT8 aucStaticBuf[DMS_LOG_STATIC_ONE_BUF_SIZE*DMS_LOG_STATIC_BUF_NUM + 32] = {0};
#endif
VOS_UINT8 *g_aucStaticBuf = NULL;

extern VOS_UINT32 dms_debug_flag;

/*****************************************************************************
�� �� ��  : writeAtData
��������  : ATдUSB���������
�������  : ulClientId: �ͻ���ID
          aucDataBuf: ��������ָ��
          ulLen:���ͳ���
�������  :
�� �� ֵ  : ERR_MSP_FAILURE/ERR_MSP_SUCCESS
���ú���  :
��������  : Dms_WriteAtData
�޸���ʷ  :
1.��    ��  : 2012��8��27��
  �޸�����  : Creat Function
*****************************************************************************/

VOS_UINT32 writeAtData(VOS_UINT32 ulClientId, VOS_UINT8 *aucDataBuf, VOS_UINT32 ulLen)
{
    VOS_UINT32 ret = ERR_MSP_SUCCESS;
    VOS_UINT8 *pSenBuf  = VOS_NULL;

    if (VOS_NULL == aucDataBuf || 0 == ulLen)
    {
        return ERR_MSP_FAILURE;
    }

    /*���� PCUI ͨ�������� */
    if (ulClientId == EN_DMS_AT_CLIENT_CTRL)
    {
        pSenBuf = Dms_GetStaticBuf(ulLen);

        if(pSenBuf ==VOS_NULL)
        {
            return ERR_MSP_FAILURE;
        }

        VOS_MemCpy(pSenBuf, aucDataBuf, ulLen);

        ret = dms_VcomWriteAsync(EN_DMS_BEARER_USB_COM_CTRL,pSenBuf,(VOS_UINT32)ulLen);

        if( ret != ERR_MSP_SUCCESS)
        {
            Dms_FreeStaticBuf( pSenBuf );
        }

    }
    /*���� CTRL ͨ�������� */
    else if (ulClientId == EN_DMS_AT_CLIENT_ACM)
    {

        pSenBuf = Dms_GetStaticBuf(ulLen);

        if(pSenBuf ==VOS_NULL)
        {
            return ERR_MSP_FAILURE;
        }

        VOS_MemCpy(pSenBuf, aucDataBuf, ulLen);

        ret = dms_VcomWriteAsync(EN_DMS_BEARER_USB_COM4_AT,pSenBuf,(VOS_UINT32)ulLen);

        if( ret != ERR_MSP_SUCCESS)
        {
            Dms_FreeStaticBuf( pSenBuf );
        }

    }
    /*���� NDIS CTRL ͨ�������� */
    else if(ulClientId == EN_DMS_AT_CLIENT_NCM)
    {
        pSenBuf = Dms_GetStaticBuf(ulLen);

        if(pSenBuf ==VOS_NULL)
        {
            return ERR_MSP_FAILURE;
        }

        VOS_MemCpy(pSenBuf, aucDataBuf, ulLen);

        ret = dms_NcmSendData(pSenBuf,(VOS_UINT32)ulLen);

        if( ret != ERR_MSP_SUCCESS)
        {
            Dms_FreeStaticBuf( pSenBuf );
        }
    }
    else
    {
        ret = ERR_MSP_INVALID_PARAMETER;
    }

    return ret;
}

/*****************************************************************************
 �� �� ��  : Dms_WriteAtData
 ��������  : ATд���������
 �������  : ucPortNo: ͨ��ID
             pData: ��������ָ��
             uslength:���ͳ���
 �������  :
 �� �� ֵ  : ERR_MSP_FAILURE/ERR_MSP_SUCCESS
 ���ú���  :
 ��������  :
 �޸���ʷ  :
   1.��    ��  : 2012��8��27��
     �޸�����  : Creat Function
*****************************************************************************/

VOS_INT32 Dms_WriteAtData(VOS_UINT8 ucPortNo, VOS_UINT8* pData, VOS_UINT16 uslength)
{
    VOS_INT32 slRet = -1;
    VOS_UINT32 ulClientId = 0;

    if (VOS_TRUE == dms_debug_flag)
    {
        vos_printf("Dms_WriteAtData: PortNo = %d, len = %d, buf = %s\r\n", ucPortNo, uslength, pData);
    }

    if(EN_DMS_BEARER_USB_COM4_AT == ucPortNo)
    {
        ulClientId = EN_DMS_AT_CLIENT_ACM;
    }
    else if(EN_DMS_BEARER_USB_NCM == ucPortNo)
    {
        ulClientId =  EN_DMS_AT_CLIENT_NCM;
    }

    else if(EN_DMS_BEARER_USB_COM_CTRL == ucPortNo)
    {
        ulClientId = EN_DMS_AT_CLIENT_CTRL;
    }
    else
    {
        return slRet;
    }

    slRet = (VOS_INT32)writeAtData(ulClientId, pData, (VOS_UINT32)uslength);

    return slRet;
}

/*****************************************************************************
 �� �� ��  : Dms_StaticBufInit
 ��������  : AT���;�̬buf��ʼ��
 �������  :

 �������  :
 �� �� ֵ  :
 ���ú���  :
 ��������  :
 �޸���ʷ  :
   1.��    ��  : 2012��8��27��
     �޸�����  : Creat Function
*****************************************************************************/

VOS_VOID Dms_StaticBufInit(VOS_VOID)
{
    VOS_UINT32 i = 0;
    VOS_UINT8 * pTemp = NULL;

#if (VOS_LINUX== VOS_OS_VER)
    VOS_UINT32 ulBufSize;

    ulBufSize = (DMS_LOG_STATIC_ONE_BUF_SIZE*DMS_LOG_STATIC_BUF_NUM + 32);
    g_aucStaticBuf = kmalloc(ulBufSize, GFP_KERNEL|__GFP_DMA);

    if(g_aucStaticBuf == VOS_NULL)
    {
        return ;
    }
#endif

#if (VOS_WIN32== VOS_OS_VER)
    g_aucStaticBuf = aucStaticBuf;
#endif

    /*ȡ32�ֽڶ���ĵ�ַ*/
    pTemp = g_aucStaticBuf + (32 - ((VOS_UINT32 )g_aucStaticBuf%32));

    stDmsStaticBufInfo.enBufType      = EN_DMS_DYMIC_BUF_TYP;

    /* ��ʼ��������Ϣ*/
    for (i = 0; i < DMS_LOG_STATIC_BUF_NUM; i++)
    {
        stDmsStaticBufInfo.stBufSta[i].buf    = (VOS_UINT8 *)(i * DMS_LOG_STATIC_ONE_BUF_SIZE + pTemp);
        stDmsStaticBufInfo.stBufSta[i].enBusy = EN_STATIC_BUF_STA_IDLE;
    }

    return ;

}
/*****************************************************************************
�� �� ��  : Dms_GetStaticBuf
��������  : AT���ͻ�ȡ��̬buf
�������  : ulLen :��Ҫbuf�ĳ���

�������  :
�� �� ֵ  : VOS_NULL/addr
���ú���  :
��������  :
�޸���ʷ  :
 1.��    ��  : 2012��8��27��
   �޸�����  : Creat Function
*****************************************************************************/

VOS_UINT8* Dms_GetStaticBuf(VOS_UINT32 ulLen)
{
    VOS_UINT32 i = 0;
    VOS_UINT32 *buf = NULL;

    /*���ݳ��ȳ�����̬buf���size����̬����buf*/
    if(ulLen >DMS_LOG_STATIC_ONE_BUF_SIZE )
    {

#if (VOS_LINUX== VOS_OS_VER)
        buf = kmalloc(ulLen, GFP_KERNEL|__GFP_DMA);
#else
        buf = VOS_NULL;
#endif
        return (VOS_UINT8* )buf;
    }

    for (i = 0; i < DMS_LOG_STATIC_BUF_NUM; i++)
    {
        if (stDmsStaticBufInfo.stBufSta[i].enBusy == EN_STATIC_BUF_STA_IDLE)
        {
            stDmsStaticBufInfo.stBufSta[i].enBusy = EN_STATIC_BUF_STA_BUSY;

            return  stDmsStaticBufInfo.stBufSta[i].buf;
        }
    }

    /*���޳����� �����̬buf���꣬���붯̬�ڴ�ʹ��*/
#if (VOS_LINUX== VOS_OS_VER)
    buf = kmalloc(ulLen, GFP_KERNEL|__GFP_DMA);
#else
    buf = VOS_NULL;
#endif

    return (VOS_UINT8* )buf;

}

/*****************************************************************************
�� �� ��  : Dms_IsStaticBuf
��������  : �ж��Ƿ��Ǿ�̬��ַ
�������  : buf: buf��ַ

�������  :
�� �� ֵ  : TRUE/FALSE
���ú���  :
��������  :
�޸���ʷ  :
1.��    ��  : 2012��8��27��
  �޸�����  : Creat Function
*****************************************************************************/

 VOS_BOOL Dms_IsStaticBuf(VOS_UINT8 *buf)
 {

    if(( buf >= g_aucStaticBuf )
        &&(buf < g_aucStaticBuf +DMS_LOG_STATIC_ONE_BUF_SIZE * DMS_LOG_STATIC_BUF_NUM  +32))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

/*****************************************************************************
 �� �� ��  : Dms_FreeStaticBuf
 ��������  : �ͷž�̬�ռ�
 �������  : buf: ���ͷŵ�buf��ַ

 �������  :
 �� �� ֵ  :
 ���ú���  :
 ��������  :
 �޸���ʷ  :
   1.��    ��  : 2012��8��27��
     �޸�����  : Creat Function
*****************************************************************************/

VOS_VOID Dms_FreeStaticBuf( VOS_UINT8 * buf)
{
    VOS_UINT32 i = 0;

    if (NULL == buf)
    {
        return ;
    }

    /*��̬buf�ͷ�*/
    for (i = 0; i < DMS_LOG_STATIC_BUF_NUM; i++)
    {
        if (stDmsStaticBufInfo.stBufSta[i].buf == buf)
        {
            stDmsStaticBufInfo.stBufSta[i].enBusy = EN_STATIC_BUF_STA_IDLE;
            return ;
        }
    }

    /*��̬buf�ͷ�*/
    if(i == DMS_LOG_STATIC_BUF_NUM)
    {
#if (VOS_LINUX== VOS_OS_VER)
        kfree(buf );
#endif
    }


    return ;
}
/*****************************************************************************
 �� �� ��  : dms_VcomWriteAsync
 ��������  : USB�첽д�ӿ�
 �������  : VcomId: ͨ��ID
             pucDataBuf: ����ָ��
             slLen:���ͳ���
 �������  :
 �� �� ֵ  : ERR_MSP_FAILURE/ERR_MSP_SUCCESS
 ���ú���  :
 ��������  :
 �޸���ʷ  :
   1.��    ��  : 2012��8��27��
     �޸�����  : Creat Function
*****************************************************************************/

VOS_UINT32 dms_VcomWriteAsync(VOS_UINT32 VcomId,VOS_UINT8 *pucDataBuf,VOS_UINT32 ulLen)
{
    VOS_INT32 ret = ERR_MSP_SUCCESS;
    ACM_WR_ASYNC_INFO  stVcom  = {0};
    VOS_INT32 slHandle = 0;
    DMS_PHY_BEAR_PROPERTY_STRU* aenPhyBear = dmsgetPhyBearProperty();

    stVcom.pBuffer = (VOS_CHAR*)pucDataBuf;
    stVcom.u32Size = ulLen;

    /*LTE DIAG CTRL*/
    if (VcomId == EN_DMS_BEARER_USB_COM1_DIAG_CTRL)
    {
        slHandle = aenPhyBear[EN_DMS_BEARER_USB_COM1_DIAG_CTRL].slPortHandle;

        if(slHandle == UDI_INVALID_HANDLE)
        {
            return ERR_MSP_FAILURE;
        }

        DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM1_WRT, ulLen, 0, 0);

        ret = udi_ioctl((int)slHandle, ACM_IOCTL_WRITE_ASYNC, &stVcom);

        if(ret == ERR_MSP_SUCCESS)
        {
            DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM1_WRT_SUCC, ulLen, 0, 0);
        }

    }
    /*LTE DIAG DATA*/
    else if(VcomId == EN_DMS_BEARER_USB_COM2_DIAG_APP)
    {
        slHandle = aenPhyBear[EN_DMS_BEARER_USB_COM2_DIAG_APP].slPortHandle;

        if(slHandle == UDI_INVALID_HANDLE)
        {
            return ERR_MSP_FAILURE;
        }

        DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM2_WRT, ulLen, 0, 0);
        ret = udi_ioctl((int)slHandle, ACM_IOCTL_WRITE_ASYNC, &stVcom);

        if(ret == ERR_MSP_SUCCESS)
        {
            DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM2_WRT_SUCC, ulLen, 0, 0);
        }

    }
    /*AT PCUI*/
    else if(VcomId == EN_DMS_BEARER_USB_COM4_AT)
    {
        slHandle = aenPhyBear[EN_DMS_BEARER_USB_COM4_AT].slPortHandle;

        if(slHandle == UDI_INVALID_HANDLE)
        {
            if (VOS_TRUE == dms_debug_flag)
            {
                vos_printf("dms_VcomWriteAsync: INVALID HANDLE\r\n");
            }

            return ERR_MSP_FAILURE;
        }

        if(aenPhyBear[EN_DMS_BEARER_USB_COM4_AT].ucChanStat ==ACM_EVT_DEV_SUSPEND)
        {
            if (VOS_TRUE == dms_debug_flag)
            {
                vos_printf("dms_VcomWriteAsync: DEV SUSPEND\r\n");
            }

            return ERR_MSP_FAILURE;
        }

        DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM_AT_WRT, ulLen, 0, 0);

        ret = udi_ioctl((int)slHandle, ACM_IOCTL_WRITE_ASYNC, &stVcom);

        if(ret == ERR_MSP_SUCCESS)
        {
            DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM_AT_WRT_SUSS, ulLen, 0, 0);
        }

    }
    /*AT CTRL*/
    else if(VcomId == EN_DMS_BEARER_USB_COM_CTRL)
    {
        slHandle = aenPhyBear[EN_DMS_BEARER_USB_COM_CTRL].slPortHandle;

        if(slHandle == UDI_INVALID_HANDLE)
        {
            return ERR_MSP_FAILURE;
        }

        DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM_CTRL_WRT, ulLen, 0, 0);

        ret = udi_ioctl((int)slHandle, ACM_IOCTL_WRITE_ASYNC, &stVcom);

        if(ret == ERR_MSP_SUCCESS)
        {
            DMS_DEBUG_SDM_FUN(EN_SDM_DMS_VCOM_CTRL_WRT_SUSS, ulLen, 0, 0);
        }

    }
    else
    {
        ret = ERR_MSP_INVALID_PARAMETER;
    }

    return (VOS_UINT32)ret;
}


