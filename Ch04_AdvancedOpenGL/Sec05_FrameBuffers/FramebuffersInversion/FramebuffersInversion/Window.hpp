//
//  Window.hpp
//  FramebuffersInversion
//
//  Created by shenyuanluo on 2017/9/5.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


typedef enum __retStatus {
    Ret_failure             = 0,        /* 失败 */
    Ret_success             = 1,        /* 成功 */
}RetStatus;


class Window
{
private:
    
    GLFWwindow*     m_window;           /** 窗体实例 */
    const GLuint    m_width;            /** 窗体宽度 */
    const GLuint    m_height;           /** 窗体高度 */
    const GLchar*   m_title;            /** 窗体标题 */
    std::string     m_cwd;              /** 可执行文件路径 */

    GLfloat m_currFTime;                /* 当前帧时间 */
    GLfloat m_lastFTime;                /* 上一帧时间 */
    GLfloat m_dealFTime;                /* 每一帧处理时间 */
    
    GLuint m_framebuffer;               /* 帧缓冲 */
    GLuint m_fbAttachTexture;           /* 帧缓冲·纹理附件 */
    GLuint m_fbAttachRBO;               /* 帧缓冲·渲染缓存附件 */
    
    
    /**
     创建 GLFW 窗体实例

     @return GLFW 实例
     */
    GLFWwindow* createWindow();
    
    /**
     初始化 GLAD
     
     @return 参见‘RetStatus’
     */
    RetStatus initGlad();
    
    /**
     获取文件的绝对路径
     
     @param filePath 文件相对路径
     @return 绝对路径
     */
    std::string fullPath(const std::string &filePath);
    
    /**
     创建帧缓冲

     @param attachTexture 帧缓冲·纹理附件
     @param attachRBO 帧缓冲·渲染缓冲对象附件
     @return 帧缓冲
     */
    GLuint createFramebuffer(GLuint* attachTexture, GLuint* attachRBO);
    
    /**
     处理用户输入回调
     
     @param window GLFW 窗体实例
     */
    void processInput(GLFWwindow* window);
    
    /**
     清理资源
     */
    void clearWindow();
    
    /**
     GLFW 错误回调
     
     @param errorCode 错误代码
     @param description 错误描述
     */
    static void errorCallback(GLint errorCode, const GLchar* description);
    
    /**
     GLFW 窗体大小回调
     
     @param window GLFW 窗体实例
     @param width 窗体款第
     @param height 窗体高度
     */
    static void frameBufferSizeCB(GLFWwindow* window, GLint width, GLint height);
    
    /**
     鼠标（移动）事件回调

     @param window GLFW 窗体实例
     @param posX 鼠标当前位置 x 坐标
     @param posY 鼠标当前位置 y 坐标
     */
    static void mouseMoveCB(GLFWwindow* window, GLdouble posX, GLdouble posY);
    
    /**
     鼠标（滚动）事件回调

     @param window GLFW 窗体实例
     @param offsetX 鼠标滚动 x 偏移量
     @param offsetY 鼠标滚动 y 偏移量
     */
    static void mouseScrollCB(GLFWwindow* window, GLdouble offsetX, GLdouble offsetY);
    
    
public:
    Window(GLuint width, GLuint height, const GLchar* title);
    
    ~Window();
    
    /**
     设置可执行文件所在目录·绝对路径
     
     @param cwdPath 可执行文件绝对路径
     */
    void setCWD(const std::string &cwdPath);
    
    /**
     渲染
     */
    void render();
};

#endif /* Window_hpp */

