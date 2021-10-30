//
// Created by liruijie666 on 2021/10/30.
//
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "CommodityInterface.h"

#define NUM 90

using namespace std;

void CommodityInterface::Initialize(shopInterface &shopInterface) {
    string init_names[NUM] = {
        "熟食", "水果", "蔬菜", "本地特产", "进口食品", "面包", "蛋糕", "泡面", "饼干", "干果", 
        "水", "果汁", "脉动", "红牛", "可乐", "雪碧", "红酒", "白酒", "牛奶", "茶", 
        "台式电脑", "笔记本电脑", "键盘", "鼠标", "显示器", "智能手机", "智能手表", "耳机", "平板电脑", "电子书", 
        "小学教材", "中学教材", "大学教材", "文学作品", "艺术鉴赏", "儿童读物", "外语教材", "专业图书", "工具书", "历史书籍", 
        "纸巾", "洗发水", "沐浴露", "护发素", "毛巾", "牙刷/牙膏", "洗衣液", "柔顺剂", "消毒剂", "清洁液", 
        "洗衣机", "抽油烟机", "洗碗机", "烘干机", "豆浆机", "吸尘器", "电磁炉", "电视", "冰箱", "加湿器", 
        "上衣", "裤子", "裙子", "鞋", "羽绒服", "男士内衣", "cosplay服", "女士内衣", "帽子", "其他部件", 
        "铅笔", "钢笔", "中性笔", "橡皮", "修正带", "便利贴", "胶带", "剪刀", "卡纸", "美术工具", 
        "足球", "篮球", "排球", "乒乓球", "羽毛球", "高尔夫", "台球", "空竹", "网球", "橄榄球"
    };
    float init_price[NUM] = {
        21.0, 13.8, 7.5, 55, 68, 6, 25.6, 4.5, 10, 90,
        2.5, 4.5, 5, 7, 3, 3, 150, 688, 12, 245,
        7899, 6999, 399, 249, 1899, 6399, 2489, 499, 3688, 4237,
        44.5, 67, 233, 55, 487, 23, 77.8, 123, 244, 94,
        12, 32, 43, 45.5, 20, 32, 25.7, 54, 22, 39,
        2387, 3398, 2499, 1299, 1588, 899, 1299, 4568, 6999, 239,
        366, 289, 435, 899, 1399, 45, 999, 46, 129, 233,
        10, 88, 12, 3.9, 7.8, 2.5, 4, 15, 8, 25,
        188, 243, 199, 15, 45, 399, 34, 55, 88, 278
    };
    unsigned seed = time(0);
    srand(seed);
    CommodityInformation *commodity;
    map<CommodityInformation *, int> tempList = shopInterface.getCommodityList();
    int amount, ID;
    for(int i = 0; i < NUM; i++) {
        amount = rand() % 1000 + 100;
        ID = i + 10;
        commodity = commodityFactory.getSingleCommodity(ID, init_names[i], init_price[i], ID / 10, amount);
        tempList[commodity] = ID;
    }
    shopInterface.setCommodityList(tempList);
}

void CommodityInterface::MainInterface(shopInterface &shopInterface) {
    Initialize(shopInterface);
}
