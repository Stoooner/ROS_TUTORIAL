#include "ros/ros.h"
/*
    需要实现参数的查询：
        实现：1. ros::NodeHandle;
                    param(键,默认值) 
                        存在，返回对应结果，否则返回默认值

                    getParam(键,存储结果的变量)
                        存在,返回 true,且将值赋值给参数2
                        若果键不存在，那么返回值为 false，且不为参数2赋值

                    getParamCached键,存储结果的变量)--提高变量获取效率
                        存在,返回 true,且将值赋值给参数2
                        若果键不存在，那么返回值为 false，且不为参数2赋值

                    getParamNames(std::vector<std::string>)
                        获取所有的键,并存储在参数 vector 中 

                    hasParam(键)
                        是否包含某个键，存在返回 true，否则返回 false

                    searchParam(参数1，参数2)
                        搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
             2. ros::param;
*/
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    // 初始化ROS节点
    ros::init(argc, argv, "get_param_c");
    // 创建ROS节点句柄
    ros::NodeHandle nh;
    // 1. ros::NodeHandle::param(键, 默认值), 存在，返回对应结果，否则返回默认值
    double radius = nh.param("radius", 0.5);
    ROS_INFO("radius = %.2f", radius);

    // 2. ros::NodeHandle::getParam(键,存储结果的变量), 存在,返回true,且将值赋值给参数2; 
    // 如果键不存在，那么返回值为 false，且不为参数2赋值
    double radius2 = 0.0;
    bool result = nh.getParam("radius_param", radius2);
    if (result){
        ROS_INFO("获取的半径是：%.2f", radius2);
    }else{
        ROS_INFO("被查询的变量不存在！");
    }

    // 3. ros::NodeHandle::getParamCached(键, 存储结果的变量)--提高变量获取效率
    // 若存在,返回true,且将值赋值给参数2; 如果键不存在，那么返回值为false，且不为参数2赋值
    // getParamCached与getParam类似，只是性能上有提升，一般的测试下，性能的提升不大看得出来
    result = nh.getParamCached("radius", radius2);
    if (result){
        ROS_INFO("获取的半径是：%.2f", radius2);
    }else{
        ROS_INFO("被查询的变量不存在！");
    }

    // 4. ros::NodeHandle::getParamNames(std::vector<std::string>) 获取所有的键,并存储在参数vector中
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name:names){
        ROS_INFO("遍历到的元素： %s", name.c_str());
    }

    // 5. ros::NodeHandle::hasParam(键), 是否包含某个键，存在返回 true，否则返回 false
    bool flag1 = nh.hasParam("type_param");
    bool flag2 = nh.hasParam("type_param_xxx");
    ROS_INFO("flag1 = %d, flag2 = %d", flag1, flag2);

    // 6. ros::NodeHandle::searchParam(参数1，参数2), 搜索键，参数1是被搜索的键，参数2存储搜索结果的变量名
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("搜索结果: %s", key.c_str());

    // ---------------------------------------------------
    double radius3 = ros::param::param("radius", 100.5);
    ROS_INFO("radius3 = %.2f", radius3);

    std::vector<std::string> names_params;
    ros::param::getParamNames(names_params);
    for (auto &&name:names_params){
        ROS_INFO("键： %s", name.c_str());
    }
    
    return 0;
}