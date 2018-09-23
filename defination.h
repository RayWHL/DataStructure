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

#define SCR_ROW 25             /*��Ļ����*/
#define SCR_COL 80             /*��Ļ����*/

#define LISTINCREMENT 5         /*�����ڴ���*/

#define TRUE 1
#define true 1
#define error 0
#define ERROR 0

//��ʦ��Ϣ�ṹ
typedef struct teacher_info{
    char name[15];
    char rank[10];
    int course_number;
    struct teacher_info *next;
}TEACHER_INFO;

//������Ϣ
typedef struct classroom_name{
    char classroom[20];
    int number;
    struct classroom_name *next;
}CLASSROOM_NAME;

//������Ϣ�ṹ
typedef struct classroom_info{
    char classroom_building[20];    //����¥����
    int classroom_number;           //¥��������
    struct classroom_name *head;          //ָ���¥�������ҵ���ͷ
}CLASSROOM_INFO;


//������Ϣ��ͷ���
typedef struct classroom_list{
    CLASSROOM_INFO *elem;
    int length;
    int listsize;
}CLASSROOM_LIST;

//�༶��Ϣ�ṹ
typedef struct class_info{
    int class_name;
    int student_number;
    struct class_info *next;
}CLASS_INFO;

//�༶��Ժϵ��Ϣ�ṹ
typedef struct class_faculty_info{
    char faculty[40];
    int class_number;
    struct class_info *head;
}CLASS_FACULTY_INFO;

//�༶��Ϣ��ͷ���
typedef struct class_list{
    CLASS_FACULTY_INFO *elem;
    int length;
    int listlize;
}CLASS_LIST;

//��ʦ����
typedef struct teacher_name{
    char teacher[20];
}TEACHER_NAME;

//�α������Ϣ
typedef struct class_info_graph{
    int class_number;       //�ϰ���
    int class_name[5];      //�����༶
    int teacher_number;
    TEACHER_NAME teacher[20];
    int week_prior, week_next;
    int day;        //�ܼ�
    int course_prior, course_next;  //  ���ڿ�
    char building[20];  //�γ�����¥������
    char classroom[20];     //�γ����ڽ�������
    struct class_info_graph *next;
}CLASS_INFO_GRAPH;

//�α�γ���Ϣ
typedef struct course_info_graph{
    char course_name[50];
    int class_number;         //�ÿγ̿�����
    CLASS_INFO_GRAPH *next_class;
    struct course_info_graph *next;
}COURSE_INFO_GRAPH;

//�γ̱�רҵͷ���
typedef struct course_graph{
    char faculty[40];       //רҵ����
    int year;       //��
    int grade;      //�꼶
    int time;       //���＾  1Ϊ�� 2Ϊ��
    COURSE_INFO_GRAPH *next_course;     //�γ���Ϣ���Ա�ͷ
    int number_course;       //�γ���
    struct course_graph *next;     //��һ�γ̱�
}COURSE_GRAPH;

/**
 *��Ļ������Ϣ�������ṹ
 */
typedef struct layer_node {
    char LayerNo;            /**< �������ڲ���*/
    SMALL_RECT rcArea;       /**< ����������������*/
    CHAR_INFO *pContent;     /**< �������������ַ���Ԫԭ��Ϣ�洢������*/
    char *pScrAtt;           /**< �������������ַ���Ԫԭ����ֵ�洢������*/
    struct layer_node *next; /**< ָ����һ����ָ��*/
} LAYER_NODE;

/**
 *��ǩ���ṹ
 */
typedef struct labe1_bundle {
    char **ppLabel;        /**< ��ǩ�ַ��������׵�ַ*/
    COORD *pLoc;           /**< ��ǩ��λ�����׵�ַ*/
    int num;               /**< ��ǩ����*/
} LABEL_BUNDLE;

/**
 *�����ṹ
 */
typedef struct hot_area {
    SMALL_RECT *pArea;     /**< ������λ�����׵�ַ*/
    char *pSort;           /**< �������(�������ı���ѡ���)�����׵�ַ*/
    char *pTag;            /**< ������������׵�ַ*/
    int num;               /**< ��������*/
} HOT_AREA;

extern LAYER_NODE *gp_top_layer;                 /*����������Ϣ����ͷ*/
extern COURSE_GRAPH *gp_head;                    /*��ͷָ��*/
extern CLASSROOM_LIST g_classroom;               /*������Ϣ*/
extern CLASS_LIST g_class;                       /*�༶��Ϣ*/
extern TEACHER_INFO *gp_teacher;                  /*��ʦ��Ϣ*/


extern char *gp_sys_name;    /*ϵͳ����*/


extern char *gp_graph_faculty_filename ;        /*�α�Ժϵ������Ϣ�����ļ�*/
extern char *gp_graph_classes_filename;                /*�α�༶������Ϣ�����ļ�*/
extern char *gp_graph_course_filename;                /*�α�γ̻�����Ϣ�����ļ�*/
extern char *gp_graph_class_filename;                /*�α���û�����Ϣ�����ļ�*/
extern char *gp_teacher_filename;                   /*��ʦ������Ϣ�����ļ�*/
extern char *gp_classroom_building_filename;                /*����¥��������Ϣ�����ļ�*/
extern char *gp_class_filename;                     /*�༶������Ϣ�����ļ�*/

extern int gi_sel_menu;                       /*��ѡ�е����˵����,��ʼΪ1*/
extern int gi_sel_sub_menu;                    /*��ѡ�е��Ӳ˵����,��ʼΪ0,��ʾδѡ��*/

extern CHAR_INFO *gp_buff_menubar_info;     /*��Ų˵�����Ļ���ַ���Ϣ�Ļ�����*/
extern CHAR_INFO *gp_buff_stateBar_info;    /*���״̬����Ļ���ַ���Ϣ�Ļ�����*/



extern char *gp_scr_att;    /*�����Ļ���ַ���Ԫ����ֵ�Ļ�����*/
extern char gc_sys_state;   /*��������ϵͳ״̬���ַ�*/


HANDLE gh_std_out;          /*��׼����豸���*/
HANDLE gh_std_in;           /*��׼�����豸���*/


//int CreatList();              /*���������ʼ��*/
void InitInterface(void);                 /*ϵͳ�����ʼ��*/
void ClearScreen(void);                         /*����*/
void ShowMenu(void);                            /*��ʾ�˵���*/
void PopMenu(int num);                          /*��ʾ�����˵�*/
void PopPrompt(int num);                        /*��ʾ��������*/
void PopUp(SMALL_RECT *, WORD, LABEL_BUNDLE *, HOT_AREA *);  /*����������Ļ��Ϣά��*/
void PopOff(void);                              /*�رն��㵯������*/
void DrawBox(SMALL_RECT *parea);                /*���Ʊ߿�*/
void LocSubMenu(int num, SMALL_RECT *parea);    /*���˵������˵���λ*/
void ShowState(void);                           /*��ʾ״̬��*/
void TagMainMenu(int num);                      /*��Ǳ�ѡ�е����˵���*/
void TagSubMenu(int num);                       /*��Ǳ�ѡ�е��Ӳ˵���*/
int DealConInput(HOT_AREA *phot_area, int *pihot_num);  /*����̨���봦��*/
void SetHotPoint(HOT_AREA *phot_area, int hot_num);     /*��������*/
void RunSys(COURSE_GRAPH **pphd);                  /*ϵͳ����ģ���ѡ�������*/
int ExeFunction(int main_menu_num, int sub_menu_num);  /*����ģ��ĵ���*/
void CloseSys(COURSE_GRAPH *phd);                  /*�˳�ϵͳ*/
int ShowModule(char **pString, int n);

int LoadData(void);           /*���ݼ���*/
int SaveData(void);           /*��������*/
int ExitSys(void);            /*�˳�ϵͳ*/
int HelpTopic(void);          /*��������*/

int MaintainClassroom_Add(void);    /*���ӽ���*/
int MaintainClassroom_Modify(void);    /*�޸Ľ���*/
int MaintainClassroom_Delete(void);    /*ɾ������*/

int MaintainClass_Modify(void);   /*�޸İ༶��Ϣ*/
int MaintainClass_Add(void);   /*���Ӱ༶��Ϣ*/
int MaintainClass_Delete(void);   /*ɾ���༶��Ϣ*/

int MaintainTeacher_Modify(void);   /*�޸Ľ�ʦ��Ϣ*/
int MaintainTeacher_Add(void);   /*���ӽ�ʦ��Ϣ*/
int MaintainTeacher_Delete(void);   /*ɾ����ʦ��Ϣ*/

int MaintainCourseGraph_Add(void);   /*���ӿγ���Ϣ*/
int MaintainCourseGraph_Delete(void);   /*ɾ���γ���Ϣ*/
int MaintainCourseGraph_Modify(void);   /*�޸Ŀγ���Ϣ*/

int MaintainClassGraph_Modify(void);   /*�޸Ŀ�����Ϣ*/
int MaintainClassGraph_Add(void);   /*���ӿ�����Ϣ*/
int MaintainClassGraph_Delete(void);   /*ɾ��������Ϣ*/

int QueryTeacher(void);       /*��ѯ��ʦְ����Ϣ*/
int QueryClassroom(void);     /*��ѯ����������Ϣ*/
int QueryClass(void);         /*��ѯ�༶������Ϣ*/
int QueryCourse(void);       /*��ѯ�γ��ον�ʦ��Ϣ*/
int QueryClassGraph(void);    /*��ѯ������Ϣ*/
int QueryFreeClassroom(void);    /*��ѯ���н���*/

int SearchCourseByTeacher(void);        /*����ʦ��������*/
int SearchCourseByClass(void);        /*���༶��������*/
int SearchCourseByCourse(void);         /*���γ̼�������*/
int SearchCourseByClassroom(void);         /*�����Ҽ�������*/
int SearchCourseByTime(void);         /*��ʱ���������*/

int AnalysisUsingRate(void);            /*���������ʷ���*/
int AnalysisCourseByTeacher(void);            /*��ʦ�е����ú����Է���*/
int AnalysisCourseByClass(void);            /*�༶������õĺ����Է���*/
int AnalysisEnergy(void);               /*��Ч����*/

int TraversalGraph(void);               /*�α����*/
int TraversalClass(void);               /*�༶����*/
int TraversalClassroom(void);             /*���ұ���*/
int TraversalTeacher(void);               /*��ʦ����*/

#endif /**< TYPE_H_INCLUDED*/

