#pragma once
/*
                                                  
                     777             7777         
                7777222227777       777777        
               772222221222277       7777         
              77222222272222277                   
              77222272727222277                   
              77222227272722277                   
               7727222727222777                   
               77777222227777777777777777777      
             77777777777777777240888888880577     
           721522777777777772108804512515277      
         77408880422777772244880277               
       775088888888445554400888427                
     77488892272508888888888880477                
    728888577  7724888888080888427                
   77488027      77540080808088027                
    775277        77448080808880577               
      77         7724888888888880477              
                724088888888888888427             
              7758888012277222240888427           
             7758889577       77720888477         
             72088927            774888477        
            77508017              775088577       
            72988477               77488427       
            7200927                 7288857       
            777277                  77488477      
                                      7777        

              有人物联网  www.usr.cn   

			  by zzming   2017-12-07
                                                  
*/
                                                  
///////////////////////////////
///////  初始化和释放  ////////
///////////////////////////////

//获取版本
typedef long(_stdcall *FN_USR_GetVer)();
//初始化
typedef boolean(_stdcall *FN_USR_Init)(LPCWSTR Host, unsigned short Port, long Ver);
//释放
typedef boolean(_stdcall *FN_USR_Release)();

///////////////////////////////
////////  连接和断开  /////////
///////////////////////////////

//连接回调
typedef void(_stdcall *TUSR_ConnAckEvent)(long ReturnCode, LPCWSTR Description);
typedef boolean(_stdcall *FN_USR_OnConnAck)(TUSR_ConnAckEvent OnConnAct);
//连接
typedef boolean(_stdcall *FN_USR_Connect)(LPCWSTR Username, LPCWSTR Password);
//断开
typedef boolean(_stdcall *FN_USR_DisConnect)();

///////////////////////////////
//////  订阅和取消订阅  ///////
///////////////////////////////

//订阅回调
typedef void(_stdcall *TUSR_SubscribeAckEvent)(long MessageID, LPCWSTR SubFunName, LPCWSTR SubParam, LPCWSTR ReturnCode);
typedef boolean(_stdcall *FN_USR_OnSubscribeAck)(TUSR_SubscribeAckEvent OnSubscribeAck);
//取消订阅回调
typedef void(_stdcall *TUSR_UnSubscribeAckEvent)(long MessageID, LPCWSTR UnSubFunName, LPCWSTR UnSubParam);
typedef boolean(_stdcall *FN_USR_OnUnSubscribeAck)(TUSR_UnSubscribeAckEvent OnUnSubscribeAck);

// 订阅单个设备解析后的数据  【云组态】
typedef long(_stdcall *FN_USR_SubscribeDevParsed)(LPCWSTR DevId);
// 订阅账户下所有设备解析后的数据  【云组态】
typedef long(_stdcall *FN_USR_SubscribeUserParsed)(LPCWSTR Username);
// 取消订阅单个设备解析后的数据  【云组态】
typedef long(_stdcall *FN_USR_UnSubscribeDevParsed)(LPCWSTR DevId);
// 取消订阅账户下所有设备解析后的数据  【云组态】
typedef long(_stdcall *FN_USR_UnSubscribeUserParsed)(LPCWSTR Username);

// 订阅单个设备原始数据流 【云交换机】
typedef long(_stdcall *FN_USR_SubscribeDevRaw)(LPCWSTR DevId);
// 订阅账户下所有设备原始数据流 【云交换机】
typedef long(_stdcall *FN_USR_SubscribeUserRaw)(LPCWSTR Username);
// 取消订阅单个设备原始数据流 【云交换机】
typedef long(_stdcall *FN_USR_UnSubscribeDevRaw)(LPCWSTR DevId);
// 取消订阅账户下所有设备原始数据流 【云交换机】
typedef long(_stdcall *FN_USR_UnSubscribeUserRaw)(LPCWSTR Username);


///////////////////////////////
/////////  推送消息 ///////////
///////////////////////////////

//推送回调
typedef void(_stdcall *TUSR_PubAckEvent)(long MessageID);
typedef boolean(_stdcall *FN_USR_OnPubAck)(TUSR_PubAckEvent OnPubAck);

// 设置数据点值【云组态】
typedef long(_stdcall *FN_USR_PublishParsedSetSlaveDataPoint)(LPCWSTR DevId, LPCWSTR SlaveIndex, LPCWSTR PointId, LPCWSTR Value);
// 查询数据点值【云组态】
typedef long(_stdcall *FN_USR_PublishParsedQuerySlaveDataPoint)(LPCWSTR DevId, LPCWSTR SlaveIndex, LPCWSTR PointId);
// 向单台设备推送原始数据流 【云交换机】
typedef long(_stdcall *FN_USR_PublishRawToDev)(LPCWSTR DevId, void *pData, long DataLen);
// 向账户下所有设备推送原始数据流 【云交换机】
typedef long(_stdcall *FN_USR_PublishRawToUser)(LPCWSTR Username, void *pData, long DataLen);

///////////////////////////////
/////////  接收消息 ///////////
///////////////////////////////

// 接收设备解析后的数据 事件 【云组态】
typedef void(_stdcall *TUSR_RcvParsedEvent)(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr);

// 设置 接收数据点推送 回调函数 【云组态】
typedef boolean(_stdcall *FN_USR_OnRcvParsedDataPointPush)(TUSR_RcvParsedEvent OnRcvParsed);
// 设置 接收设备上下线推送 回调函数 【云组态】
typedef boolean(_stdcall *FN_USR_OnRcvParsedDevStatusPush)(TUSR_RcvParsedEvent OnRcvParsed);
// 设置 接收设备报警推送 回调函数 【云组态】
typedef boolean(_stdcall *FN_USR_OnRcvParsedDevAlarmPush)(TUSR_RcvParsedEvent OnRcvParsed);
// 设置 接收数据点操作应答 【云组态】
typedef boolean(_stdcall *FN_USR_OnRcvParsedOptionResponseReturn)(TUSR_RcvParsedEvent OnRcvParsed);

// 接收设备原始数据流 事件 【云交换机】 
typedef void(_stdcall *TUSR_RcvRawEvent)(long MessageID, LPCWSTR DevId, void *pData, long DataLen);
// 设置 接收设备原始数据流 回调函数 【云交换机】
typedef boolean(_stdcall *FN_USR_OnRcvRawFromDev)(TUSR_RcvRawEvent OnRcvRaw);

/////////////////////////////////////////
/////////  不再建议使用的函数 ///////////
/////////  不再建议使用的函数 ///////////
/////////  不再建议使用的函数 ///////////
/////////////////////////////////////////

// 设置单台设备数据点值【云组态】, 用 FN_USR_PublishParsedSetSlaveDataPoint 代替
typedef long(_stdcall *FN_USR_PublishParsedSetDataPoint)(LPCWSTR DevId, LPCWSTR PointId, LPCWSTR Value);
// 查询单台设备数据点值【云组态】,用 FN_USR_PublishParsedQuerySlaveDataPoint 代替
typedef long(_stdcall *FN_USR_PublishParsedQueryDataPoint)(LPCWSTR DevId, LPCWSTR PointId);