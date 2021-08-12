#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
    发布方实现：
        1. 包含头文件: ROS中的文本类型--->std_msgs/String.h
        2. 初始化ROS节点；
        3. 创建节点句柄；
        4. 创建发布者对象；
        5. 编写发布逻辑并发布数据
        6. 打印当前发布者发布的数据: rostopic echo xxxxxxtopic
    
    第三章 ROS通信机制进阶知识点：
    3.1 初始化ROS节点：void init(int &argc, char **argv, const std::string& name, uint32_t options = 0);
        参数：
            1. argc ---> 封装的实参个数(int类型，假定在键盘上输入的参数个数为n, 那么argc对应的个数为n+1)
            2. argv ---> 封装参数的数组
            3. name ---> 为节点定义的名称(具有唯一性)
            4. options ---> 节点启动选项
            返回值： void
        使用：
            1. argc与argv的使用
               如果按照ROS中的特定格式传入实参，那么ROS可以加以使用，比如用来设置全局参数或者给节点进行重命名...
               这里设置全局参数的特定格式: _paramname:=paramvalue
            2. options的使用
               问题： 节点名称需要保证唯一，会导致一个问题: 同一个节点不能重复启动；
               现象： 如果重复启动的话，新启动的这个同名节点会把旧的节点给挤掉，旧的节点会被关闭；
               需求： 特定场景下，需要一个节点多次启动且能正常运行，怎么办？
               解决： ros::init(argc, argv, "info_publisher", ros::init_options::AnonymousName);
                     ros::init_options::AnonymousName能够解决重名问题，其实现机制是在现有的这个重名节点
                     后面加上一个随机数--->info_publisher_xxxxxxx, 从而解决重名问题；
                     可以通过rosnode list查看节点名
*/

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 2. 初始化ROS节点；
    ros::init(argc, argv, "info_publisher", ros::init_options::AnonymousName);
    // 3. 创建节点句柄；
    ros::NodeHandle nh;
    // 4. 创建发布者对象；
    /*
        第三章 ROS通信机制进阶知识点：
        3.2.1 发布者对象
        ros::NodeHandle nh;
        ros::Publisher pub = nh.advertise<templete>("topic_name", queue_size);
        template <class M>
        Publisher advertise(const std::string& topic, uint32_t queue_size, bool latch = false)
            作用： 
                创建发布者对象
            模板：
                要进行发布的消息的类型
            参数：
                - topic 发布消息使用的话题；
                - queue_size 等待发送给订阅者的最大消息数量；
                - latch (optional) 如果为 true,该话题发布的最后一条消息将被保存，
                                   并且后期当有订阅者连接时会将该消息发送给订阅者；
                - return 调用成功时，会返回一个发布对象；
            使用：
                latch设置为true的作用? 
                以静态地图发布为例，方案1：可以使用固定频率发送地图数据，但是效率太低；
                方案2：可以将地图发布对象的latch设置为true，并且发布方只发送一次数据，
                每当订阅者连接时就可将地图数据发送给订阅者(只发送一次)，这样提高了数据的发送效率
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("house", 10, true);
    // 5. 编写发布逻辑并发布数据, 要求以10HZ的频率发布数据, 并且文本后添加编号
    // 5.1 先创建被发布的消息
    std_msgs::String msg;
    // 5.2 发布频率--->10HZ
    ros::Rate rate(10);
    // 5.3 设置编号
    int count = 0;
    ros::Duration(3).sleep(); // 持续休息3秒再发布，避免出现发布信息早于发布者注册这一行为的出现，从而造成订阅者订阅的信息出现前面几条丢失
    // 5.3 编写循环，循环发布数据， ros::ok()代表节点只要还活着，则该循环就是成立的
    while(ros::ok()){
        count ++;
        // msg.data = "hello";
        // 实现字符串拼接
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str(); // 将ss中的数据提取的为字符串
        // 针对3.2.1 发布者对象api讲解进行的修改
        if (count <= 10){
            pub.publish(msg);
            // 添加日志
            ROS_INFO("发布的数据是: %s", ss.str().c_str());
        }
        rate.sleep();
        /*
            在ROS程序中，频繁的使用了ros::spin()和ros::spinOnce()两个回旋函数，可以用于处理回调函数。
                相同点: 二者都用于处理回调函数；
                不同点: ros::spin() 是进入了循环执行回调函数，而ros::spinOnce()只会执行一次回调函数(没有循环)，
                       在ros::spin()后的语句不会执行到，而ros::spinOnce()后的语句可以执行。
        */
        ros::spinOnce(); // 官方建议, 处理回调函数，只不过这里发布函数里暂时没用到回调函数，因此这一句可用可不用
        ROS_INFO("一轮回调执行完毕...");
    }
    return 0;
}