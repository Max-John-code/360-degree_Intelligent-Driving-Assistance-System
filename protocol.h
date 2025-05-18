#pragma once

#define POLYNOMIAL 0x04C11DB7
#define POLY_INIT  0xFFFFFFFF
#define POLY_END   0x00000000

#include <cstdint>

typedef struct head
{
    //type：1-注册 2-注册返回 3-登录 4-登陆返回 5-视频保存 6-视频翻页
    //7-视频翻页返回 8-视频进度更新 9-视频保存返回 10-心跳协议
    //11-视频进度更新返回 12-图片上传结构体 13-图片发送完成确认协议体
    //14-图片丢失协议体 15-图片信息保存数据库请求
    //16-图片查询请求 17-图片信息返回包
    int businessType;//业务类型
   int businessLength;//业务长度（体长度）
    uint32_t CRC;
}HEAD;
//注册协议体
typedef struct reg
{
    char user_account[10];//用户账号
    char user_name[10];//用户名
    char user_pwd[50];//用户密码，MD5
}REG;
//注册返回协议体
typedef struct tback
{
    int flag;//成功标志 0-失败 1-成功
}TBACK;
//登录协议体
typedef struct login
{
    char user_account[10];//用户账号
    char user_pwd[50];//用户密码，MD5
}LOGIN;
//视频结构体
typedef struct video_info
{
    char video_path[50];//视频路径
    char video_cover[50];//视频首帧路径
    char video_time[30];//视频录制时间
    int video_cur;//视频当前帧数
    int video_num;//视频总帧数
}VIDEO_INFO;
//登录返回协议体
typedef struct login_back
{
    int flag;//成功标志 0-失败 1-成功 -1-账号错误 -2密码错误
    char user_name[10];//用户名
    int video_count;	//该用户视频总个数
    //VIDEO_INFO videoArr[6];//视频结构体数组
}LOGIN_BACK;
//视频保存协议体
typedef struct video_save
{
    char video_path[50];//视频路径
    int video_num;//视频总帧数
    char video_cover[50]; // 视频首帧路径
    char video_time[30]; //视频录制时间
    char user_account[10];//用户账号
}VIDEO_SAVE;
//视频翻页协议体
typedef struct turn_page
{
    int page; //视频页数，0是切换界面 page*6+1 6
    char user_acount[10];   //用户账号
}TURN_PAGE;
//视频翻页返回协议体
typedef struct back_page
{
    int flag;// 成功标志 0 - 失败 1 - 成功
    VIDEO_INFO videoArr[6];//视频结构体数组
    int video_count;	//该用户视频总个数
}BACK_PAGE;
//视频进度更新
typedef struct schedule_save
{
    char video_time[30]; //视频录制时间
    int video_cur;	//视频当前帧数
    char user_acount[10];   //用户账号
}SCHEDULE_SAVE;

//视频保存返回
typedef struct video_back
{
    int flag;//成功标志 0-失败 1-成功
}VIDEO_BACK;

//视频进度更新返回协议体
typedef struct schedule_back
{
    int flag;//成功标志 0-失败 1-成功
}SCHEDULE_BACK;

//图片上传结构体
typedef struct fileinfo
{
    char account[10];//用户名
    char filename[50];//文件名
    char filepath[50];//客户端本地路径
    int fileLegth;//文件总字节
    int fileNum;//碎片文件总数
    int fileindex;//当前碎片文件序号
    int length;//当前碎片文件字节数
    char context[1000]; //文件二进制内容（当前碎片文件）
}FILEINFO;

//图片发送完成确认协议体
typedef struct  file_finish
{
    char account[10];//用户名
    char filename[50];//文件名
}FILE_FINISH;

//图片丢失协议体
typedef struct file_loss
{
    int count;  //总共要发几个协议体
    int cur;    //当前是第几个协议体
    int fileCount;  //丢包的文件总数
    char filename[50];//文件名
    char buf[1000];  //例：buf[1000] ={1,8,100,0000000000000......}
}FILE_LOSS;

//协议体15
//服务器对图片信息的反馈→客户端
//图片信息结构体
typedef struct photo
{
    char photoPath[50];            //图片存储路径
    char traitPhotoTime[30];    //特征图片存储时间
    int allBytes;                //总字节数
    char photoName[30];            //特征图片名字
    char user_account[10];        //用户账号
}PHOTO;

//图片信息返回包
typedef struct getPhotosInfo
{
    int allPhoto;               //返回图片总个数
    int flag;                    //正确和错误
    PHOTO photoArr[9];            //图片信息结构体数组 默认9个
}GET_PHOTOS_INFO;

//图片查询协议体
typedef struct turn_picture
{
    int page; //图片页数，0是切换界面 page*9+1 9
    char user_acount[10];   //用户账号
}TURN_PICTURE;

