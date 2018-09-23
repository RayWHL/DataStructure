#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <ctype.h>
#include <time.h>

#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#define SCR_ROW 25             /*屏幕行数*/
#define SCR_COL 80             /*屏幕列数*/

#define LISTINCREMENT 5         /*新增内存数*/

#define TRUE 1
#define true 1
#define error 0
#define ERROR 0

//教师信息结构
typedef struct teacher_info{
    char name[15];
    char rank[10];
    int course_number;
    struct teacher_info *next;
}TEACHER_INFO;

//教室信息
typedef struct classroom_name{
    char classroom[20];
    int number;
    struct classroom_name *next;
}CLASSROOM_NAME;

//教室信息结构
typedef struct classroom_info{
    char classroom_building[20];    //教室楼栋名
    int classroom_number;           //楼栋教室数
    struct classroom_name *head;          //指向该楼栋各教室的链头
}CLASSROOM_INFO;


//教室信息表头结点
typedef struct classroom_list{
    CLASSROOM_INFO *elem;
    int length;
    int listsize;
}CLASSROOM_LIST;

//班级信息结构
typedef struct class_info{
    int class_name;
    int student_number;
    struct class_info *next;
}CLASS_INFO;

//班级的院系信息结构
typedef struct class_faculty_info{
    char faculty[40];
    int class_number;
    struct class_info *head;
}CLASS_FACULTY_INFO;

//班级信息表头结点
typedef struct class_list{
    CLASS_FACULTY_INFO *elem;
    int length;
    int listlize;
}CLASS_LIST;

//教师名称
typedef struct teacher_name{
    char teacher[20];
}TEACHER_NAME;

//课表课堂信息
typedef struct class_info_graph{
    int class_number;       //合班数
    int class_name[5];      //各个班级
    int teacher_number;
    TEACHER_NAME teacher[20];
    int week_prior, week_next;
    int day;        //周几
    int course_prior, course_next;  //  两节课
    char building[20];  //课程所在楼栋名称
    char classroom[20];     //课程所在教室名称
    struct class_info_graph *next;
}CLASS_INFO_GRAPH;

//课表课程信息
typedef struct course_info_graph{
    char course_name[50];
    int class_number;         //该课程课堂数
    CLASS_INFO_GRAPH *next_class;
    struct course_info_graph *next;
}COURSE_INFO_GRAPH;

//课程表专业头结点
typedef struct course_graph{
    char faculty[40];       //专业名称
    int year;       //年
    int grade;      //年级
    int time;       //春秋季  1为秋 2为春
    COURSE_INFO_GRAPH *next_course;     //课程信息线性表头
    int number_course;       //课程数
    struct course_graph *next;     //下一课程表
}COURSE_GRAPH;

/**
 *屏幕窗口信息链结点结点结构
 */
typedef struct layer_node {
    char LayerNo;            /**< 弹出窗口层数*/
    SMALL_RECT rcArea;       /**< 弹出窗口区域坐标*/
    CHAR_INFO *pContent;     /**< 弹出窗口区域字符单元原信息存储缓冲区*/
    char *pScrAtt;           /**< 弹出窗口区域字符单元原属性值存储缓冲区*/
    struct layer_node *next; /**< 指向下一结点的指针*/
} LAYER_NODE;

/**
 *标签束结构
 */
typedef struct labe1_bundle {
    char **ppLabel;        /**< 标签字符串数组首地址*/
    COORD *pLoc;           /**< 标签定位数组首地址*/
    int num;               /**< 标签个数*/
} LABEL_BUNDLE;

/**
 *热区结构
 */
typedef struct hot_area {
    SMALL_RECT *pArea;     /**< 热区定位数组首地址*/
    char *pSort;           /**< 热区类别(按键、文本框、选项框)数组首地址*/
    char *pTag;            /**< 热区序号数组首地址*/
    int num;               /**< 热区个数*/
} HOT_AREA;

extern LAYER_NODE *gp_top_layer;                 /*弹出窗口信息链链头*/
extern COURSE_GRAPH *gp_head;                    /*主头指针*/
extern CLASSROOM_LIST g_classroom;               /*教室信息*/
extern CLASS_LIST g_class;                       /*班级信息*/
extern TEACHER_INFO *gp_teacher;                  /*教师信息*/


extern char *gp_sys_name;    /*系统名称*/


extern char *gp_graph_faculty_filename ;        /*课表院系基本信息数据文件*/
extern char *gp_graph_classes_filename;                /*课表班级基本信息数据文件*/
extern char *gp_graph_course_filename;                /*课表课程基本信息数据文件*/
extern char *gp_graph_class_filename;                /*课表课堂基本信息数据文件*/
extern char *gp_teacher_filename;                   /*教师基本信息数据文件*/
extern char *gp_classroom_building_filename;                /*教室楼栋基本信息数据文件*/
extern char *gp_class_filename;                     /*班级基本信息数据文件*/

extern int gi_sel_menu;                       /*被选中的主菜单项号,初始为1*/
extern int gi_sel_sub_menu;                    /*被选中的子菜单项号,初始为0,表示未选中*/

extern CHAR_INFO *gp_buff_menubar_info;     /*存放菜单条屏幕区字符信息的缓冲区*/
extern CHAR_INFO *gp_buff_stateBar_info;    /*存放状态条屏幕区字符信息的缓冲区*/



extern char *gp_scr_att;    /*存放屏幕上字符单元属性值的缓冲区*/
extern char gc_sys_state;   /*用来保存系统状态的字符*/


HANDLE gh_std_out;          /*标准输出设备句柄*/
HANDLE gh_std_in;           /*标准输入设备句柄*/


//int CreatList();              /*数据链表初始化*/
void InitInterface(void);                 /*系统界面初始化*/
void ClearScreen(void);                         /*清屏*/
void ShowMenu(void);                            /*显示菜单栏*/
void PopMenu(int num);                          /*显示下拉菜单*/
void PopPrompt(int num);                        /*显示弹出窗口*/
void PopUp(SMALL_RECT *, WORD, LABEL_BUNDLE *, HOT_AREA *);  /*弹出窗口屏幕信息维护*/
void PopOff(void);                              /*关闭顶层弹出窗口*/
void DrawBox(SMALL_RECT *parea);                /*绘制边框*/
void LocSubMenu(int num, SMALL_RECT *parea);    /*主菜单下拉菜单定位*/
void ShowState(void);                           /*显示状态栏*/
void TagMainMenu(int num);                      /*标记被选中的主菜单项*/
void TagSubMenu(int num);                       /*标记被选中的子菜单项*/
int DealConInput(HOT_AREA *phot_area, int *pihot_num);  /*控制台输入处理*/
void SetHotPoint(HOT_AREA *phot_area, int hot_num);     /*设置热区*/
void RunSys(COURSE_GRAPH **pphd);                  /*系统功能模块的选择和运行*/
int ExeFunction(int main_menu_num, int sub_menu_num);  /*功能模块的调用*/
void CloseSys(COURSE_GRAPH *phd);                  /*退出系统*/
int ShowModule(char **pString, int n);

int LoadData(void);           /*数据加载*/
int SaveData(void);           /*保存数据*/
int ExitSys(void);            /*退出系统*/
int HelpTopic(void);          /*帮助主体*/

int MaintainClassroom_Add(void);    /*增加教室*/
int MaintainClassroom_Modify(void);    /*修改教室*/
int MaintainClassroom_Delete(void);    /*删除教室*/

int MaintainClass_Modify(void);   /*修改班级信息*/
int MaintainClass_Add(void);   /*增加班级信息*/
int MaintainClass_Delete(void);   /*删除班级信息*/

int MaintainTeacher_Modify(void);   /*修改教师信息*/
int MaintainTeacher_Add(void);   /*增加教师信息*/
int MaintainTeacher_Delete(void);   /*删除教师信息*/

int MaintainCourseGraph_Add(void);   /*增加课程信息*/
int MaintainCourseGraph_Delete(void);   /*删除课程信息*/
int MaintainCourseGraph_Modify(void);   /*修改课程信息*/

int MaintainClassGraph_Modify(void);   /*修改课堂信息*/
int MaintainClassGraph_Add(void);   /*增加课堂信息*/
int MaintainClassGraph_Delete(void);   /*删除课堂信息*/

int QueryTeacher(void);       /*查询教师职称信息*/
int QueryClassroom(void);     /*查询教室容量信息*/
int QueryClass(void);         /*查询班级人数信息*/
int QueryCourse(void);       /*查询课程任课教师信息*/
int QueryClassGraph(void);    /*查询课堂信息*/
int QueryFreeClassroom(void);    /*查询空闲教室*/

int SearchCourseByTeacher(void);        /*按教师检索课堂*/
int SearchCourseByClass(void);        /*按班级检索课堂*/
int SearchCourseByCourse(void);         /*按课程检索课堂*/
int SearchCourseByClassroom(void);         /*按教室检索课堂*/
int SearchCourseByTime(void);         /*按时间检索课堂*/

int AnalysisUsingRate(void);            /*教室利用率分析*/
int AnalysisCourseByTeacher(void);            /*教师承担课堂合理性分析*/
int AnalysisCourseByClass(void);            /*班级参与课堂的合理性分析*/
int AnalysisEnergy(void);               /*能效分析*/

int TraversalGraph(void);               /*课表遍历*/
int TraversalClass(void);               /*班级遍历*/
int TraversalClassroom(void);             /*教室遍历*/
int TraversalTeacher(void);               /*教师遍历*/

#endif /**< TYPE_H_INCLUDED*/

