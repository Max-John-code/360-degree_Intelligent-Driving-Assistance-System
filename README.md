# 360度智能行车辅助系统客户端

## 项目简介

360度智能行车辅助系统是基于Socket网络通讯技术和OpenCV视觉处理技术实现的智能驾驶辅助系统。该系统通过安装在车身前后左右的2~4个摄像头，同时采集车辆四周的影像，经过图像处理技术对图像进行畸变还原、视角转化、图像拼接、图像增强等处理，最终形成一幅无缝完整的车周全景鸟瞰图。驾驶员通过配合标尺线能够准确读出障碍物的位置和距离，有效提升行车安全性。

本仓库为360度智能行车辅助系统的客户端部分，基于Qt框架开发，提供了友好的用户界面和丰富的功能。

## 系统架构

整个360度智能行车辅助系统由三大部分构成：
- **设备客户端**（本仓库）：负责视频采集、图像处理和用户交互
- **终端服务器**：负责数据存储和管理
- **大并发压力测试程序**：用于系统性能测试

## 主要功能

1. **用户管理**
   - 用户注册与登录
   - 用户身份验证

2. **视频处理**
   - 实时视频采集
   - 视频播放与回放
   - 视频存储与管理

3. **图像处理**
   - 多路摄像头图像拼接
   - 全景鸟瞰图生成
   - 障碍物识别与距离测量

4. **数据同步**
   - 与服务器的数据同步
   - 文件上传与下载
   - 心跳检测保持连接

## 技术特点

- 采用大并发通信框架思想和自定义协议
- 基于TCP/IP通讯协议封装了通信组件
- 实现了动态数组以及线程池等技术的通信框架
- 使用OpenCV进行图像处理和计算机视觉分析
- 多线程技术保证系统高效运行
- 自定义协议保证通信可靠性和安全性

## 开发环境

- 操作系统：Linux
- 开发框架：Qt
- 图像处理：OpenCV
- 网络通信：Socket API
- 编译工具：C++11

## 项目结构

```
.
├── Thread/              # 线程相关模块
│   ├── camdecode.cpp    # 摄像头解码线程
│   ├── decode.cpp       # 视频解码线程
│   ├── heartbeatthread.cpp # 心跳线程
│   ├── readthread.cpp   # 数据读取线程
│   ├── sendtask.cpp     # 数据发送任务
│   ├── splitfile.cpp    # 文件分片线程
│   └── writethread.cpp  # 数据写入线程
├── view/                # 界面相关模块
│   ├── bootwidget.cpp   # 启动界面
│   ├── loginwidget.cpp  # 登录界面
│   ├── mainwidget.cpp   # 主界面
│   ├── regwidget.cpp    # 注册界面
│   └── videowidget.cpp  # 视频播放界面
├── protocol.h           # 通信协议定义
├── socketconnect.cpp    # Socket连接模块
├── videolistitem.cpp    # 视频列表项
└── main.cpp             # 程序入口
```

## 安装与使用

### 前置条件

- Qt 5.x 或更高版本
- OpenCV 4.x 或更高版本
- C++11 兼容的编译器

### 编译步骤

1. 安装Qt和OpenCV依赖：
   ```
   # Debian/Ubuntu系统
   sudo apt-get install qt5-default libopencv-dev
   
   # CentOS/RHEL系统
   sudo yum install qt5-qtbase-devel opencv-devel
   ```

2. 克隆项目：
   ```
   git clone https://github.com/yourusername/DrivingAssistanceSystem.git
   cd DrivingAssistanceSystem
   ```

3. 编译项目：
   ```
   qmake
   make
   ```

4. 运行程序：
   ```
   ./DrivingAssitanceItem
   ```

## 配置说明

在使用前，需要配置服务器连接参数：

1. 打开应用
2. 进入"设置"界面
3. 配置服务器IP地址和端口
4. 保存配置

## 使用流程

1. 注册/登录系统
2. 系统将自动连接到配置的服务器
3. 连接摄像头设备
4. 选择行车模式或鸟瞰模式
5. 开始使用系统进行驾驶辅助

## 项目背景

本项目是卓跃教育嵌入式班级学生在《5G物联网视觉开发》阶段和《Linux基础开发》阶段的综合实践项目，旨在检验学生对多线程、网络通信、OpenCV视觉处理等技术的掌握程度，并培养团队协作能力。

## 贡献指南

欢迎对项目进行贡献！贡献方式：

1. Fork本仓库
2. 创建功能分支 (`git checkout -b feature/your-feature`)
3. 提交更改 (`git commit -m 'Add some feature'`)
4. 推送到分支 (`git push origin feature/your-feature`)
5. 创建Pull Request

## 许可证

本项目采用 [MIT许可证](LICENSE) 
