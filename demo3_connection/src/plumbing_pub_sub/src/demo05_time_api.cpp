#include "ros/ros.h"
/*
    需求1: 演示时间相关操作(获取当前时间 + 设定指定时刻)
    实现: 
        1. 准备(头文件、节点初始化、NodeHandle创建...), 需要注意的是时间相关的头文件已经在ros.h中被包含了，
           所有不需要额外再导入什么时间相关的头文件了;
        2. 获取当前时刻;
        3. 设置指定时刻;

    需求2： 程序执行中停顿5秒
    实现：
        1. 创建持续时间对象
        2. 休眠

    需求3： 已知程序开始运行的时刻和程序运行的时间，求程序运行结束的时刻
    实现：
        1. 获取开始执行的时刻；
        2. 模拟运行时间(N秒)；
        3. 计算结束时间 = 开始时刻 + 持续时间；

    需求4：每隔1秒钟，在控制台输出一段文本
    实现：
        1. 方法1：ros::Rate(1);
        2. 方法2：定时器
*/

// 回调函数
void cb(const ros::TimerEvent& event){
    ROS_INFO("----Time_Event.");
    ROS_INFO("函数被调用的时刻: %.2f", event.current_real.toSec());
}

int main(int argc, char *argv[]){
    // 1. 准备(头文件、节点初始化、NodeHandle创建...)
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "Time_API");
    ros::NodeHandle nh; // 这一步是必须的, 没有此步骤的话会导致时间API调用失败(在NodeHandle中会初始化时间操作)
    // 2. 获取当前时刻(now函数会将当前时刻封装会返回)
    // 当前时刻指的是now被调用执行的那一刻
    // 参考系：1970年01月01日 00:00:00
    // right_now得出的就是距离参考系所逝去的时间总长
    ROS_INFO("==============================时刻==============================");
    ros::Time right_now = ros::Time::now();
    // toSec方法是将逝去的时间总长转换成秒数
    ROS_INFO("当前时刻:%.2f", right_now.toSec());//获取距离1970年01月01日 00:00:00 的秒数
    ROS_INFO("当前时刻:%d", right_now.sec);//获取距离 1970年01月01日 00:00:00 的秒数

    // 3. 设置指定时刻
    ros::Time someTime(100,100000000);// 参数1:秒数  参数2:纳秒
    ROS_INFO("时刻:%.2f",someTime.toSec()); //100.10
    ros::Time someTime2(100.3);//直接传入 double 类型的秒数
    ROS_INFO("时刻:%.2f",someTime2.toSec()); //100.30

    // 4. 持续时间
    ROS_INFO("==============================持续时间==============================");
    ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());
    ros::Duration du(5);//持续5秒钟,参数是double类型的，以秒为单位
    du.sleep();//按照指定的持续时间休眠
    ROS_INFO("持续时间:%.2f",du.toSec());//将持续时间换算成秒
    ROS_INFO("当前时刻:%.2f",ros::Time::now().toSec());
    
    ROS_INFO("==============================时刻计算==============================");
    // 5.1 获取开始执行的时刻
    ros::Time begin = ros::Time::now();
    // 5.2 模拟运行时间(N秒)
    ros::Duration du1(5);
    // 5.3 计算结束时间 = 开始时刻 + 持续时间
    // 运算符进行了重载，使得两个Time类型能够直接进行相加
    ros::Time stop = begin + du1;
    ROS_INFO("开始时刻: %.2f", begin.toSec());
    ROS_INFO("结束时刻: %.2f", stop.toSec());

    // 5.4 时刻与时刻的运算
    // 时刻与时刻之间是不能进行相加运算操作的
    // ros::Time sum = begin + stop;
    // 时刻与时刻之间能够进行相减操作，不过得出的返回值类型不是Time类型，而是ros::Duration类型
    ros::Duration du2 = begin - stop;
    ROS_INFO("时刻相减: %.2f", du2.toSec());

    // 5.5 持续时间与持续时间的运算
    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du1 + du2 = %.2f", du3.toSec());
    ROS_INFO("du1 - du2 = %.2f", du4.toSec());

    /*
        1. Time对象与Duration对象相加减结果都是Time对象；
        2. Duration对象之间相加减的结果都是Duration对象；
        2. Time对象相减结果是Duration对象；
        3. Time对象之间不能相加；
    */

    ROS_INFO("==============================定时器==============================");
    /*
        ros::Timer createTimer(ros::Duration period,  // 时间间隔 ---> 1s
                                const ros::TimerCallback& callback, // 回调函数(时间事件 const ros::TimerEvent& event) ---> 封装业务
                                bool oneshot=false,  // 定时器是否是一次性的
                                bool autostart=true); // 定时器是否自动启动
    */
    // ros::Timer timer = nh.createTimer(ros::Duration(1), cb);
    // ros::Timer timer = nh.createTimer(ros::Duration(1), cb, true);
    ros::Timer timer = nh.createTimer(ros::Duration(1), cb, false, false);
    timer.start(); // 手动启动，在参数autostart设置为false时使用
    ros::spin(); // 需要回旋

    return 0;    
}