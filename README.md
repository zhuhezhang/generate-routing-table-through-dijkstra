@[TOC](目录)

# 1.题目
给定如下图的网络拓扑，编制程序（语言不限）输入拓扑，任意指定路由器号，生成其路由表并输出。验收时要求增加/删除原拓扑中指定的任意边、顶点，重新生成路由表。
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309211925240.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
# 2.程序说明
## 2.1设计表示
为了便于理解，按函数调用的顺序来说明程序：在执行程序调出程序菜单之前已经利用文件输入流in从文件读入图3-1的路由拓扑信息，免去了每次测试都要重新输入路由信息的操作，其中路由拓扑信息利用邻接矩阵进行存储，采用类封装函数。进去菜单之后，有六个选项可以选择，分别是1输出路由表、2删除边、3添加边、4删除顶点、5添加顶点以及6退出程序。每次执行完一个功能之后会返回此主菜单（6退出程序除外），选择退出程序之后会调用类的析构函数释放存放路由拓扑信息的邻接矩阵。下图是对应的函数调用关系流程图。 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212303388.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
 ## 2.2详细设计
这里只说明在此程序中小组共同完成或者是本人自己负责的函数，源码的文件名已被修改过，不过可以对照源码后面的解释看。
首先是头文件Dijkstra_head.h：该部分由小组共同设计完成，包含一个记录起点到每个顶点的最短路径信息的结构体以及封装所有本程序所需要的类。其中结构体中包含的信息有路由器编号router、下一跳路由next_router、目的路由des_router、路径权值value、是否访问过的标志visit以及一个初始化构造函数；而类里面的public包含的函数有构造Graph、析构~Graph、创建图Create_graph、迪杰斯特拉算法求最短路径Dijkstra、输出路由表Display_table、添加边Add_edge、删除边Del_edge、添加顶点Add_vertex、删除顶点Del_vertex、程序菜单这些函数Menu，private里面包含图顶点个数vernum、图的边数edge、邻接矩阵adjmatrix、记录各个顶点最短路径的信息结构体node。
接着是主函数文件Dijkstra_main.cpp：该部分由小组共同设计完成。首先是定义一个类对象，用此对象先是调用创建图函数，利用switch调用程序菜单，根据菜单返回的数字执行相应的函数，每执行完一个函数之后（除了退出程序）利用goto语句返回switch结构的最开始部分再次调用菜单继续执行相应的函数，基本上就是这样。
然后是我所负责的创建图函数文件Dijkstra_create_graph.cpp：由于是文件录入，利用文件输入流in从文件dijkstra.txt中依次读入拓扑信息，包括数目、边数、以及边权值，并根据边的顶点确定边在邻接矩阵中的位置，最后还有一个初始化node数组的路由器编号，方便后面的操作，这部分比较简单。
算法主体部分文件Dijkstra.cpp也是我负责的：首先是输入想要输出路由表的路由器编号，根据此编号寻找其在node数组对应的下标，然后就是依次初始化node结构体数组的其他成员，然后是算法主体部分，如图所示，这里由于已经有清晰的注释便并在重复说明。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212513173.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
最后再调用输出路由表函数Display_table输出node结构体数组中的信息即可。
删除边以及删除顶点函数的文件Dijkstra_delete.cpp是我负责的最后两个函数：首先是删除边函数Del_edge，首先提示输入要删除的边（也即是删除的边的两个顶点），根据两个顶点从node数组中寻找要删除的边的下标，再根据此坐标将邻接矩阵上对应的值置为最大权值即可，也就意味着两者不可达。然后是删除顶点函数Del_vertex，根据输入删除的顶点以及node结构体数组确定其下标，然后从邻接矩阵中统计与删除的顶点相关的边数，方便后面总的边数计算。删除之后需要调整调整邻接矩阵以及node结构体数组，如下图所示。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212535654.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
## 2.3测试数据及结果
测试数据如图3-10所示，也即是刚开始创建图读入拓扑信息时所利用的数据的文件。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212602174.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
图3-10 测试数据
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212932972.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
 
图3-11 输出r3路由表       
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212947974.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)
             
图3-12 删除r5-r6边后输出的r5路由表
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309212957115.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)

图3-13 添加r5-r6边后输出的r5路由表 
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309213005461.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)

图3-14 添加顶点r1到r10、r11（权值均为1）输出r1路由表
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309213011923.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)

图3-15 删除r10输出r1 路由表                        
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210309213018732.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNzk0NjMz,size_16,color_FFFFFF,t_70#pic_center)

图3-16 删除r10输出r10路由表
## 2.4代码清单
GenerateRoutingTableDijkstraMain.cpp//此程序可以输出指定路由器路由表，该文件为主函数
GenerateRoutingTableDijkstraBody.cpp//文件包含算法主体函数，利用迪杰斯拉算法计算最短路径
GenerateRoutingTableDijkstraAdd.cpp//文件包含添加边、顶点函数
GenerateRoutingTableDijkstraCreateDraph.cpp//该文件包含创建图函数
GenerateRoutingTableDijkstraDelete.cpp//该文件包含删除边、顶点函数
GenerateRoutingTableDijkstra.h//文件包含记录起点到每个顶点的最短路径的信息结构体以及图类
GenerateRoutingTableDijkstraMenu.cpp//文件包含程序菜单
GenerateRoutingTableDijkstraOutputTable.cpp//文件包含输出路由表、析构函数
GenerateRoutingTableDijkstra.txt//存放拓扑信息文本文件
