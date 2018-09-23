#include "defination.h"

/**
 * 函数名称: MaintainClassroom_Add
 * 函数功能: 增加教室信息
 * 输入参数: 教学楼名称 教室名称 教室容量
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClassroom_Add(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：教室增加",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"教室增加成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该教室已存在！",
                           "确认"
                          };
    char *plabel_name3[] = {"内存溢出！",
                           "确认"
                          };
    CLASSROOM_INFO *newbase, *p;
    char building_name[20];
    int i;
    int flag=0;
    CLASSROOM_NAME *name, *p_name;

    name=(CLASSROOM_NAME *)malloc(sizeof(CLASSROOM_NAME));

    printf("请输入新增教室所在楼栋名称：");
    scanf("%s",building_name);
    //查找对应的教学楼
    for(i=0;i<g_classroom.length;++i)
    {
        p=g_classroom.elem+i;
        if(strcmp(p->classroom_building,building_name)==0)
        {
            flag=1;
            break;
        }
    }

    printf("请输入教室名称：");
    scanf("%s",name->classroom);
    printf("请输入教室容纳人数：");
    scanf("%d",&(name->number));
    //找到对应的教学楼
    if(flag==1)
    {
        p_name=p->head;
        //查找该教室是否已经存在
        for( ;p_name;p_name=(p_name->next))
        {
            if(strcmp(p_name->classroom, name->classroom)==0)
            break;
        }
        if(p_name==NULL)
        {
            name->next=p->head;
            p->head=name;
            ++(p->classroom_number);
            ShowModule(plabel_name1, 2);
        }
        else
            ShowModule(plabel_name2, 2);

    }
    //没有对应的教学楼，新增教学楼信息
    if(flag==0)
    {
        //内存溢出
        if(g_classroom.length>=g_classroom.listsize)
        {
        //分配新地址
            newbase=(CLASSROOM_INFO *)realloc(g_classroom.elem, (g_classroom.listsize+LISTINCREMENT)*sizeof(CLASSROOM_INFO));
            if(!newbase)        //分配失败
            {
                ShowModule(plabel_name3, 2);
                return error;
            }
            g_classroom.elem=newbase;                 //新地址
            g_classroom.listsize=g_classroom.listsize+LISTINCREMENT;        //修改容量
        }
        p=g_classroom.elem+g_classroom.length;
        strcpy(p->classroom_building, building_name);
        p->head=name;
        name->next=NULL;
        p->classroom_number=1;
        ++g_classroom.length;
        ShowModule(plabel_name1, 2);
    }
    ClearScreen();     //清屏
    ShowMenu();        //显示菜单界面
    return true;
}

/**
 * 函数名称: MaintainClassroom_Modify
 * 函数功能: 修改教室信息
 * 输入参数: 教室楼栋 教室名称
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClassroom_Modify(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：教室修改",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"教室修改成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该教室不存在！",
                           "确认"
                          };

    CLASSROOM_NAME name;
    CLASSROOM_NAME *pname;
    char building_name[20];
    CLASSROOM_INFO *pbuilding;
    int i;
    int flag=0;

    printf("请输入要修改教室的楼栋名称：");
    scanf("%s",building_name);
    printf("请输入要修改的教室名称：");
    scanf("%s",name.classroom);
    //查找对应的教学楼
    for(i=0;i<g_classroom.length;++i)
    {
        pbuilding=g_classroom.elem+i;
        if(strcmp(pbuilding->classroom_building, building_name)==0)
        {
            flag=1;
            break;
        }
    }
    //没有对应的教学楼
    if(flag==0)
        ShowModule(plabel_name2, 2);
    //找到对应的教学楼
    else
    {
        pname=pbuilding->head;
        //查找要修改的教室
        for(;pname!=NULL;pname=pname->next)
        {
            if(strcmp(pname->classroom,name.classroom)==0 )
            {
                flag=2;
                break;
            }
        }
        //找到该教室，修改信息
        if(flag==2)
        {
            printf("请输入修改后的教室名称：");
            scanf("%s",pname->classroom);
            printf("请输入修改后教室人数：");
            scanf("%d",&(pname->number));
            ShowModule(plabel_name1, 2);
        }
        else
        {
            ShowModule(plabel_name2, 2);
        }
    }
    ClearScreen();     //清屏
    ShowMenu();        //显示菜单界面
    return true;
}

/**
 * 函数名称: MaintainClassroom_Delete
 * 函数功能: 删除教室信息
 * 输入参数: 教学楼名称 教室名称
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClassroom_Delete(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：教室删除",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"教室删除成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该教室不存在！",
                           "确认"
                          };
    CLASSROOM_NAME name;
    CLASSROOM_NAME *p, *q;
    char building_name[20];
    CLASSROOM_INFO *pbuilding;
    int i;
    int flag=0;

    printf("请输入教室所在楼栋名称：");
    scanf("%s",building_name);
    printf("请输入教室名称：");
    scanf("%s",name.classroom);
    //查找对应的教学楼
    for(i=0; i<g_classroom.length; ++i)
    {
        pbuilding=g_classroom.elem+i;
        if(strcmp(pbuilding->classroom_building, building_name)==0)
        {
            flag=1;
            break;
        }
    }
    //找到教学楼
    if(flag==1)
    {
        q=NULL;
        p=pbuilding->head;
        //如果第一个节点对应的教室为该教室
        if(strcmp(p->classroom, name.classroom)==0)
        {
            pbuilding->head=p->next;
            free(p);
            --(pbuilding->classroom_number);
            ShowModule(plabel_name1, 2);
        }
        else
        {
            q=p;
            //依次向后遍历查找该教室
            for(p=p->next; p!=NULL; p=p->next)
            {
                if(strcmp(p->classroom, name.classroom)==0)
                {
                    flag=2;
                    q->next=p->next;
                    free(p);
                    --(pbuilding->classroom_number);    //教室数减一
                    ShowModule(plabel_name1, 2);
                    break;
                }
                q=p;
            }
            if(flag==1)
                ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ShowModule(plabel_name2, 2);
    }
    ClearScreen();     //清屏
    ShowMenu();        //显示菜单界面

    return true;
}

/**
 * 函数名称: MaintainCourseGraph_Add
 * 函数功能: 增加课程信息
 * 输入参数: 课程具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainCourseGraph_Add(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：课程信息增加",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"课程增加成功！",
                           "确认"
                          };

    char *plabel_name4[] = {"该课程已存在！",
                           "确认"
                          };
    COURSE_GRAPH *input_faculty;
    COURSE_GRAPH *p_course;
    COURSE_INFO_GRAPH *newcourse, *p;
    int flag=0;
    //分配内存
    input_faculty=(COURSE_GRAPH *)malloc(sizeof(COURSE_GRAPH));
    newcourse=(COURSE_INFO_GRAPH *)malloc(sizeof(COURSE_INFO_GRAPH));

    printf("请输入要增加的课程所在专业全称：");
    scanf("%s",input_faculty->faculty);
    printf("请输入要增加的课程的年份：");
    scanf("%d",&(input_faculty->year));
    printf("请输入要增加的课程的年级（例:2016）：");
    scanf("%d",&(input_faculty->grade));
    printf("请输入要增加的课程春秋季（1为春 2为秋）");
    scanf("%d",&(input_faculty->time));
    input_faculty->next=NULL;
    input_faculty->next_course=NULL;

    printf("情输入该课程名称：");
    scanf("%s",newcourse->course_name);

    newcourse->next_class=NULL;
    newcourse->next=NULL;

    /*
    printf("\n输入1开始录入上课时间；输入0停止录入：");
    scanf("%d",&z);
    //处理输入的课程课堂信息
    while(z==1)
    {
        newcourse_time=(COURSE_INFO_TIME *)malloc(sizeof(COURSE_INFO_TIME));
        printf("\n输入该课程上课情况：（周几 第几节至第几节课 第几周至第几周 上课楼栋 教室名）");
        scanf("%d %d %d %d %d",&(newcourse_time->day),&(newcourse_time->course_prior),
              &(newcourse_time->course_next),&(newcourse_time->week_prior) ,&(newcourse_time->week_next) );
        scanf("%s %s",(newcourse_time->building),(newcourse_time->classroom) );
        newcourse_time->next=NULL;

        if(newcourse->time_info==NULL)
            newcourse->time_info=newcourse_time;
        else
        {
            for(p_time=newcourse->time_info; p_time->next; p_time=p_time->next);
            p_time->next=newcourse_time;
        }

        printf("\n输入1继续录入，输入0停止录入:");
        scanf("%d",&z);
    }*/

    ClearScreen();                          //清屏
    ShowMenu();                             //显示菜单

   //寻找对应的专业信息
    for(p_course=gp_head; p_course!=NULL; p_course=p_course->next)
    {
        if(p_course->grade==input_faculty->grade &&
            p_course->time==input_faculty->time &&
            p_course->year==input_faculty->year &&
            strcmp(p_course->faculty, input_faculty->faculty)==0)
        {
            flag=1;
            break;
        }
    }

    //课表中不包含该课程对应的专业信息 包括课表为空，和没有对应专业信息两种情况
    if(flag==0)
    {
        input_faculty->next=gp_head;
        gp_head=input_faculty;          //将新专业课程表插入表头之前
        input_faculty->number_course=1;      //

        newcourse->next=input_faculty->next_course;
        input_faculty->next_course=newcourse;
        newcourse->class_number=0;
    }
    else            //课表包含该专业信息
    {
        for(p=p_course->next_course; p; p=p->next)
        {
            if(strcmp(p->course_name,newcourse->course_name)==0)
            {
                flag=2;
                break;
            }
        }
        if(flag!=2)
        {
            ++(p_course->number_course);
            newcourse->class_number=0;
            newcourse->next=p_course->next_course;
            p_course->next_course=newcourse;
        }
    }
    ClearScreen();                          //清屏
    ShowMenu();                             //显示菜单
    if(flag!=2)
    ShowModule(plabel_name1, 2);
    else
        ShowModule(plabel_name4,2);
    return true;
}

/**
 * 函数名称: MaintainCourseGraph_Delete
 * 函数功能: 删除课程信息
 * 输入参数: 课程所属专业信息 班级信息 课程名称
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainCourseGraph_Delete(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：课程信息删除",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"课程删除成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该课程不存在！",
                           "确认"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_course;
    COURSE_INFO_GRAPH *p_info, *p_info_prior;
    int flag=0;
    char name2[50];
    //信息输入
    printf("请输入要删除的课程专业名称：");
    scanf("%s",input_faculty.faculty);
    printf("请输入要删除的课程的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要删除的课程的年级：(例：2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要删除的课程的春秋季:（1为春2为秋） ");
    scanf("%d",&(input_faculty.time));

    printf("请输入要删除的课程的名称：");
    scanf("%s",name2);

    ClearScreen();                          //清屏
    ShowMenu();                             //显示菜单
    //查找专业信息
    for(p_course=gp_head; p_course!=NULL; p_course=p_course->next)
    {
        if(strcmp(p_course->faculty,input_faculty.faculty)==0 &&
           p_course->grade==input_faculty.grade &&
           p_course->year==input_faculty.year &&
           p_course->time==input_faculty.time)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)                 //存在该课程的专业信息
    {
        p_info=p_course->next_course;
        if(strcmp(p_info->course_name, name2)==0)
        {
            p_course->next_course=p_info->next;
            free(p_info);
            flag=2;
            --(p_course->number_course);
        }
        else
        {
            p_info_prior=p_info;
            for(p_info=p_info->next; p_info; p_info=p_info->next)
            {
                if(strcmp(p_info->course_name, name2)==0)
                {
                    p_info_prior->next=p_info->next;
                    free(p_info);
                    flag=2;
                    --(p_course->number_course);
                }
                p_info_prior=p_info;
            }
        }
        if(flag==2)
            ShowModule(plabel_name1, 2);
        else
            ShowModule(plabel_name2, 2);

    }
    else
    {
        ShowModule(plabel_name2,2);
    }

    return true;
}

/**
 * 函数名称: MaintainCourseGraph_Modify
 * 函数功能: 修改课程信息
 * 输入参数: 课程的专业信息 班级名称 课程名称
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainCourseGraph_Modify(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：课程信息修改",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"课程修改成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该课程不存在！",
                           "确认"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_course;
    COURSE_INFO_GRAPH *p_info;
    int flag=0;
    char name2[50];
    //输入信息
    printf("请输入要修改的课程专业名称：");
    scanf("%s",input_faculty.faculty);
    printf("请输入要修改的课程的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要修改的课程的年级：(例：2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要修改的课程的春秋季:（1为春2为秋） ");
    scanf("%d",&(input_faculty.time));

    printf("请输入要修改的课程的名称：");
    scanf("%s",name2);
    //查找对应课表对应的专业
    for(p_course=gp_head; p_course!=NULL; p_course=p_course->next)
    {
        if(strcmp(p_course->faculty,input_faculty.faculty)==0 &&
           p_course->grade==input_faculty.grade &&
           p_course->year==input_faculty.year &&
           p_course->time==input_faculty.time)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)         //存在该课程所在专业
    {
        for(p_info=p_course->next_course; p_info; p_info=p_info->next)
        {
            if(strcmp(p_info->course_name, name2)==0)
            {
                printf("修改后该课程名称：");
                scanf("%s",p_info->course_name);
                flag=2;
                ClearScreen();                          //清屏
                ShowMenu();
                break;

            }
        }
        if(flag==2) ShowModule(plabel_name1, 2);
        else
        {
            ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
        return true;
}

/**
 * 函数名称: MaintainClassGraph_Modify
 * 函数功能: 修改课堂信息
 * 输入参数: 课堂对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClassGraph_Modify(void)   /*修改课堂信息*/
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：课堂信息修改",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"课堂修改成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该课堂不存在！",
                           "确认"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_faculty;
    COURSE_INFO_GRAPH *p_course;
    //COURSE_INFO_TIME input_time;
    CLASS_INFO_GRAPH *p_class;
    char name2[50];
    int class_number;
    int class_name[10];
    int part1,part2,week1,week2,day;
    int i;
    int flag=0;
    //信息输入
    printf("请输入要修改的课堂专业名称：");
    scanf("%s",input_faculty.faculty);
    printf("请输入要修改的课堂的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要修改的课堂的年级：(例：2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要修改的课堂的春秋季:（1为春2为秋） ");
    scanf("%d",&(input_faculty.time));
    printf("请输入要修改的课堂的名称：");
    scanf("%s",name2);
    printf("请输入该合班数：");
    scanf("%d",&(class_number));
    printf("请输入各个班级号：");
    for(i=0; i<class_number; ++i)
        scanf("%d",class_name+i);

    printf("请输入要修改的课堂在星期几 第几节到第几节 第几周到第几周 ：");
    scanf("%d %d %d %d %d",&(day),&part1,&part2,&(week1),&week2);

    //寻找该课堂的专业对应的专业信息
    for(p_faculty=gp_head;p_faculty!=NULL;p_faculty=p_faculty->next)
    {
        if(strcmp(p_faculty->faculty,input_faculty.faculty)==0 &&
           p_faculty->grade==input_faculty.grade &&
           p_faculty->year==input_faculty.year &&
           p_faculty->time==input_faculty.time)
        {
            flag=1;
            break;
        }
    }
    //找到对应的专业信息
    if(flag==1)
    {
        for(p_course=p_faculty->next_course; p_course; p_course=p_course->next)
        {
            if(strcmp(p_course->course_name, name2)==0)
            {
                flag=2;
                break;
            }
        }
        if(flag==2)
        {
            for(p_class=p_course->next_class; p_class; p_class=p_class->next)
            {
                if(p_class->class_number==class_number &&
                   p_class->course_next==part2 &&
                   p_class->course_prior==part1 &&
                   p_class->week_next==week2 &&
                   p_class->week_prior==week1 )
                {
                    for(i=0;i<class_number;++i)
                    {
                        if(p_class->class_name[i]!=class_name[i])
                        break;
                    }
                    if(i==class_number)
                    {
                        flag=3;
                        break;
                    }
                }
            }
            if(flag==3)
            {
                printf("请输入修改后该课堂所在教学楼 教室：");
                scanf("%s %s",p_class->building,p_class->classroom);
                ClearScreen();                          //清屏
                ShowMenu();
                ShowModule(plabel_name1, 2);
            }
            else
            {
                ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
            }
        }
        else
        {
            ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
    return true;
}

/**
 * 函数名称: MaintainClassGraph_Add
 * 函数功能: 增加课堂信息
 * 输入参数: 课堂对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClassGraph_Add(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：课堂信息增加",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"课堂增加成功！",
                           "确认"
                          };
    char *plabel_name3[] = {"该课堂已存在！",
                           "确认"
                          };
    char *plabel_name2[]= {"该课堂对应课程不存在！",
                            "确认"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_faculty;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *input_class, *p_class, *p;

    input_class=(CLASS_INFO_GRAPH *)malloc(sizeof(CLASS_INFO_GRAPH));

    char name2[50];
    int i,z;
    int flag=0;
    //信息输入
    printf("请输入要增加的课堂的专业名称：");
    scanf("%s",input_faculty.faculty);
    printf("请输入要增加的课堂的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要增加的课堂的年级：(例：2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要增加的课堂的春秋季:（1为春2为秋） ");
    scanf("%d",&(input_faculty.time));
    printf("请输入要增加的课堂的课程名称：");
    scanf("%s",name2);

    printf("请输入该课堂合班数：");
    scanf("%d",&(input_class->class_number));
    printf("请输入各个班级号：");
    for(i=0; i<input_class->class_number; ++i)
        scanf("%d",input_class->class_name+i);
    printf("请输入该课堂教师数：");
    scanf("%d",&(input_class->teacher_number));
    printf("请输入教师名称：");
    for(i=0; i<input_class->teacher_number; ++i)
    {
        scanf("%s",input_class->teacher[i].teacher);
    }


    //寻找该课堂的专业对应的专业信息
    for(p_faculty=gp_head;p_faculty!=NULL;p_faculty=p_faculty->next)
    {
        if(strcmp(p_faculty->faculty,input_faculty.faculty)==0 &&
           p_faculty->grade==input_faculty.grade &&
           p_faculty->year==input_faculty.year &&
           p_faculty->time==input_faculty.time)
        {
            flag=1;
            break;
        }
    }
    //找到对应的专业信息
    if(flag==1)
    {
        for(p_course=p_faculty->next_course; p_course; p_course=p_course->next)
        {
            if(strcmp(p_course->course_name, name2)==0)
            {
                flag=2;
                break;
            }
        }
        if(flag==2)
        {
            printf("请输入1开始输入课堂时间，输入0停止输入：");
            scanf("%d",&z);
            while(z==1)
            {
                p_class=(CLASS_INFO_GRAPH *)malloc(sizeof(CLASS_INFO_GRAPH));
                printf("输入课堂时间：周几 第几节到第几节 第几周到第几周 楼栋 教室：");
                scanf("%d %d %d %d %d",&(p_class->day),&(p_class->course_prior)
                    ,&(p_class->course_next),&(p_class->week_prior),&(p_class->week_next));
                scanf("%s %s",p_class->building,p_class->classroom);
                p_class->class_number=input_class->class_number;
                for(i=0; i<input_class->class_number; ++i)
                    p_class->class_name[i]=input_class->class_name[i];
                p_class->teacher_number=input_class->teacher_number;
                for(i=0; i<input_class->teacher_number; ++i)
                    strcpy(p_class->teacher[i].teacher, input_class->teacher[i].teacher);
                p_class->next=NULL;

                for(p=p_course->next_class; p; p=p->next)
                {
                    i=0;
                    if(strcmp(p->building, input_class->building)==0 &&
                       strcmp(p->classroom, input_class->classroom)==0 &&
                       p->class_number==input_class->class_number &&
                       p->course_next==input_class->course_next &&
                       p->course_prior==input_class->course_prior &&
                       p->day==input_class->day )
                    {
                        for(i=0; i<p->class_number; ++i)
                        {
                            if(p->class_name[i]!=input_class->class_name[i])
                            {
                                break;
                            }
                        }
                    }
                    if(i==input_class->class_number)
                    {
                        flag=3;
                        break;
                    }
                }
                if(flag==3)
                {
                    ShowModule(plabel_name3, 2);
                }
                else
                {
                    if(p_course->next_class==NULL)
                        p_course->next_class=p_class;
                    else
                    {
                        for(p=p_course->next_class; p->next; p=p->next);
                        p->next=p_class;
                    }
                    ++(p_course->class_number);
                }
                printf("请输入1开始输入课堂时间，输入0停止输入：");
                scanf("%d",&z);
            }
            if(flag!=3)
            {
                ClearScreen();
                ShowMenu();
                ShowModule(plabel_name1, 2);
            }
        }
        else
        {
            ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
    return true;
}

/**
 * 函数名称: MaintainClassGraph_Delete
 * 函数功能: 删除课堂信息
 * 输入参数: 课堂对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClassGraph_Delete(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：课堂信息删除",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"课堂删除成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该课堂不存在！",
                           "确认"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_faculty;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class, input_time,*p_class_prior;
    int class_number;
    int class_name[10];
    char name2[50];
    int i;
    int flag=0;
    //课堂对应的信息输入
    printf("请输入要删除的课堂专业名称：");
    scanf("%s",input_faculty.faculty);
    printf("请输入要删除的课堂的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要删除的课堂的年级：(例：2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要删除的课堂的春秋季:（1为春2为秋） ");
    scanf("%d",&(input_faculty.time));
    printf("请输入该合班数：");
    scanf("%d",&class_number);
    printf("请输入各个班级号：");
    for(i=0; i<class_number; ++i)
        scanf("%d",class_name+i);
    printf("请输入要删除的课堂的名称：");
    scanf("%s",name2);
    printf("请输入要删除的课堂在星期几 第几节到第几节 第几周到第几周 ：");
    scanf("%d %d %d %d %d",&(input_time.day),&(input_time.course_prior),&(input_time.course_next)
          ,&(input_time.week_prior),&(input_time.week_next) );

    ClearScreen();
    ShowMenu();

    //寻找该课堂的专业对应的专业信息
    for(p_faculty=gp_head;p_faculty!=NULL;p_faculty=p_faculty->next)
    {
        if(strcmp(p_faculty->faculty,input_faculty.faculty)==0 &&
           p_faculty->grade==input_faculty.grade &&
           p_faculty->year==input_faculty.year &&
           p_faculty->time==input_faculty.time)
        {
            flag=1;
            break;
        }
    }
    //找到对应的专业信息
    if(flag==1)
    {
        for(p_course=p_faculty->next_course; p_course; p_course=p_course->next)
        {
            if(strcmp(p_course->course_name, name2)==0)
            {
                flag=2;
                break;
            }
        }
        if(flag==2)
        {
            p_class=p_course->next_class;
            if(p_class->class_number==class_number &&
                   p_class->course_next==input_time.course_next &&
                   p_class->course_prior==input_time.course_prior &&
                   p_class->week_next==input_time.week_next &&
                   p_class->week_prior==input_time.week_prior )
            {
                for(i=0;i<class_number;++i)
                {
                    if(p_class->class_name[i]!=class_name[i])
                    break;
                }
                if(i==class_number)
                {
                    p_course->next_class=p_class->next;
                    free(p_class);
                    --(p_course->class_number);
                    flag=3;
                }
            }
            else
            {
                p_class_prior=p_class;
                for(p_class=p_class->next; p_class; p_class=p_class->next)
                {
                if(p_class->class_number==class_number &&
                   p_class->course_next==input_time.course_next &&
                   p_class->course_prior==input_time.course_prior &&
                   p_class->week_next==input_time.week_next &&
                   p_class->week_prior==input_time.week_prior )
                {
                    for(i=0;i<class_number;++i)
                    {
                        if(p_class->class_name[i]!=class_name[i])
                        break;
                    }
                    if(i==class_number)
                    {
                        p_class_prior->next=p_class->next;
                        free(p_class);
                        --(p_course->class_number);
                        flag=3;
                        break;
                    }
                }
                p_class_prior=p_class;
                }
            }
            if(flag==3)
                ShowModule(plabel_name1, 2);
            else
                ShowModule(plabel_name2, 2);
        }
        else
        {
            ClearScreen();                          //清屏
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else                               //改课堂对应的专业不存在
        ShowModule(plabel_name2, 2);

    return true;
}

/**
 * 函数名称: MaintainClass_Add
 * 函数功能: 增加班级信息
 * 输入参数: 班级对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClass_Add(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：班级增加",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"班级增加成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该班级已存在！",
                           "确认"
                          };
    char *plabel_name3[] = {"内存分配失败！",
                           "确认"
                          };
    CLASS_FACULTY_INFO *newbase, *p_faculty;
    CLASS_INFO *p_class;
    CLASS_INFO *input_class;
    int flag=0;
    int i;
    char input_faculty[40];
    //分配内存
    input_class=(CLASS_INFO *)malloc(sizeof(CLASS_INFO));
    input_class->next=NULL;

    //信息输入
    printf("请输入要增加的班级所在专业的名称：");
    scanf("%s",input_faculty);
    printf("请输入要增加的班级的序号：");
    scanf("%d",&(input_class->class_name));
    printf("请输入该班级学生数：");
    scanf("%d",&(input_class->student_number));

    ClearScreen();
    ShowMenu();

    //寻找对应的专业，找到令flag等于1，且跳出循环
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(input_faculty, g_class.elem[i].faculty)==0)
        {
            flag=1;
            break;
        }
    }

    //找到对应的专业
    if(flag==1)
    {   //遍历该专业的班级查找是否存在该班级，若存在跳出循环，此时p_class不为NULL
        for(p_class=g_class.elem[i].head; p_class!=NULL; p_class=p_class->next)
        {
            if(p_class->class_name==input_class->class_name)
                break;
        }
        if(p_class==NULL)               // 不存在该班级，增加
        {
            input_class->next=g_class.elem[i].head;
            g_class.elem[i].head=input_class;       //插入链头
            ++(g_class.elem[i].class_number);
            ShowModule(plabel_name1, 2);
        }
        else            //已存在该班级，输出提示信息
            ShowModule(plabel_name2, 2);
    }
    //没找到对应的专业
    else
    {   //内存溢出，分配内存
        if(g_class.length>=g_class.listlize)
        {
            newbase=(CLASS_FACULTY_INFO *)
                    realloc(g_class.elem, (g_class.listlize+LISTINCREMENT)*sizeof(CLASS_FACULTY_INFO));
            if(newbase==NULL)                   //内存分配失败
            {
                ShowModule(plabel_name3, 2);
                return true;
            }
            g_class.elem=newbase;                               //修改内存地址
            g_class.listlize=g_class.listlize+LISTINCREMENT;    //修改可用内存长度
        }
        p_faculty=g_class.elem+g_class.length;
        strcpy(p_faculty->faculty, input_faculty);
        p_faculty->class_number=1;      //班级数为1
        ++(g_class.length);             //专业加一
        p_faculty->head=input_class;    //插入班级结点
        ShowModule(plabel_name1, 2);
    }
    return true;
}

/**
 * 函数名称: MaintainClass_Modify
 * 函数功能: 修改班级信息
 * 输入参数: 班级对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClass_Modify(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：班级修改",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"班级修改成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该班级不存在！",
                           "确认"
                          };
    CLASS_INFO *p_class;
    int flag=0;
    int i;
    int input_class;
    char input_faculty[40];
    //信息输入
    printf("请输入要修改的班级所在专业：");
    scanf("%s",input_faculty);
    printf("请输入要修改的班级序号：");
    scanf("%d",&input_class);
    //查找对应的专业
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(g_class.elem[i].faculty, input_faculty)==0)
        {
            flag=1;
            break;
        }
    }

    //找到对应的专业
    if(flag==1)
    {   //遍历该专业班级查找该班级,若找到跳出循环，此时p_class不为NULL
        for(p_class=g_class.elem[i].head; p_class!=NULL; p_class=p_class->next)
        {
            if(p_class->class_name==input_class)
                break;
        }
        //找到该班级
        if(p_class!=NULL)
        {
            printf("请输入修改后该班级人数：");
            scanf("%d",&(p_class->student_number));
            ClearScreen();
            ShowMenu();
            ShowModule(plabel_name1, 2);
        }
        //没有找到该班级
        else
        {
            ClearScreen();
            ShowMenu();
            ShowModule(plabel_name2, 2);
        }
    }
    //没有找到对应的专业
    else
    {
        ClearScreen();
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
    return true;
}

/**
 * 函数名称: MaintainClass_Delete
 * 函数功能: 删除班级信息
 * 输入参数: 班级对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainClass_Delete(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：班级删除",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"班级删除成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该班级不存在！",
                           "确认"
                          };
    char input_faculty[40];
    int input_class;
    CLASS_INFO *p_class, *p_class_prior;
    int flag=0;
    int i;
    //信息输入
    printf("请输入要删除的班级所在专业：");
    scanf("%s",input_faculty);
    printf("请输入要删除的班级序号：");
    scanf("%d",&input_class);

    ClearScreen();
    ShowMenu();

    //查找对应的专业
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(g_class.elem[i].faculty, input_faculty)==0)
        {
            flag=1;
            break;
        }
    }
    //找到对应的专业
    if(flag==1)
    {
        p_class=g_class.elem[i].head;
        //判断第一个是否是该班级
        if(p_class->class_name ==input_class)
        {
            g_class.elem[i].head=p_class->next;        //修改链表
            free(p_class);
            --(g_class.elem[i].class_number);       //该专业班级数减一
            ShowModule(plabel_name1, 2);
        }
        else
        {
            p_class_prior=p_class;      //p_class前驱
            //遍历后面的班级，查找是否存在，若存在跳出循环，此时p_class不为NULL
            for(p_class=p_class->next; p_class!=NULL; p_class=p_class->next)
            {
                if(p_class->class_name==input_class)
                    break;
                p_class_prior=p_class;
            }
            //找到该班级
            if(p_class!=NULL)
            {
                p_class_prior->next=p_class->next;    //修改链表
                free(p_class);
                --(g_class.elem[i].class_number);   // 该专业班级数减一
                ShowModule(plabel_name1, 2);
            }
            //该班级不存在
            else
                ShowModule(plabel_name2, 2);
        }
    }
    //没有找到对应的专业
    else
        ShowModule(plabel_name2, 2);
    return true;
}

/**
 * 函数名称: MaintainTeacher_Add
 * 函数功能: 增加教师信息
 * 输入参数: 教师对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainTeacher_Add(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：教师增加",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"教师增加成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该教师已存在！",
                           "确认"
                          };
    char *plabel_name3[] = {"内存分配失败！",
                           "确认"
                          };
    TEACHER_INFO *newbase, *p_teacher;
    //内存分配
    newbase=(TEACHER_INFO *)malloc(sizeof(TEACHER_INFO));
    if(newbase==NULL)
    {
        ShowModule(plabel_name3, 2);
        return true;
    }
    //教师信息输入
    printf("请输入新增教师姓名：");
    scanf("%s",newbase->name);
    printf("请输入新增教师职称：");
    scanf("%s",newbase->rank);
    ClearScreen();
    ShowMenu();
    //遍历所有教师查找是否已存在
    for(p_teacher=gp_teacher; p_teacher!=NULL; p_teacher=p_teacher->next)
    {
        if(strcmp(p_teacher->name, newbase->name)==0)
            break;
    }
    //不存在该教师
    if(p_teacher==NULL)
    {
        newbase->next=gp_teacher;
        gp_teacher=newbase;
        ShowModule(plabel_name1, 2);
    }
    else
        ShowModule(plabel_name2, 2);
    return true;
}

/**
 * 函数名称: MaintainTeacher_Delete
 * 函数功能: 删除教师信息
 * 输入参数: 教师对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainTeacher_Delete(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：教师删除",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"教师删除成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该教师不存在！",
                           "确认"
                          };
    TEACHER_INFO *p_teacher, *p_teacher_prior;
    char input_name[15];
    //教师信息输入
    printf("请输入要删除教师的名称：");
    scanf("%s",input_name);
    ClearScreen();  ShowMenu();
    p_teacher=gp_teacher;
    //链表为空
    if(gp_teacher==NULL)
    {
        ShowModule(plabel_name2, 2);
        return true;
    }

    //如果链表中第一个教师即为要删除的教师
    if(strcmp(p_teacher->name, input_name)==0)
    {
        gp_teacher=p_teacher->next;
        free(p_teacher);
        ShowModule(plabel_name1, 2);
    }
    else
    {
        p_teacher_prior=p_teacher;
        //向后遍历每个教师 查找该教师
        for(p_teacher=p_teacher->next; p_teacher!=NULL; p_teacher=p_teacher->next)
        {
            if(strcmp(p_teacher->name, input_name)==0)
                break;
            p_teacher_prior=p_teacher;
        }
        if(p_teacher==NULL)
            ShowModule(plabel_name2, 2);
        else    //找到删除该教师
        {
            p_teacher_prior->next=p_teacher->next;
            free(p_teacher);
            ShowModule(plabel_name1, 2);
        }
    }
    return true;
}

/**
 * 函数名称: MaintainTeacher_Modify
 * 函数功能: 修改教师信息
 * 输入参数: 教师对应的具体信息
 * 输出参数: 无
 * 返 回 值: true
 */
int MaintainTeacher_Modify(void)
{
    char *plabel_name[] = {"主菜单项：数据维护",
                           "子菜单项：教师修改",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"教师修改成功！",
                           "确认"
                          };
    char *plabel_name2[] = {"该教师不存在！",
                           "确认"
                          };
    TEACHER_INFO *p_teacher;
    char input_name[15];

    printf("请输入要修改的教师名称：");
    scanf("%s",input_name);
    //查找该教师，找到跳出循环
    for(p_teacher=gp_teacher; p_teacher!=NULL; p_teacher=p_teacher->next)
    {
        if(strcmp(p_teacher->name, input_name)==0)
            break;
    }
    if(p_teacher==NULL)
        ShowModule(plabel_name2, 2);
    else
    {
        printf("请输入修改后该教师的职称：");
        scanf("%s",p_teacher->rank);
        ShowModule(plabel_name1, 2);
    }
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: QuerryTeacher
 * 函数功能: 查询教师信息
 * 输入参数: 教师名称
 * 输出参数: 无
 * 返 回 值: true
 */
int QueryTeacher(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：教师职称查询",
                           "确认"
                          };
    char *plabel_name1[] = {"该教师不存在！",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    TEACHER_INFO *p_teacher;
    char input_name[15];

    printf("请输入要查询的教师名称：");
    scanf("%s",input_name);
    //遍历所有教师查询该教师
    for(p_teacher=gp_teacher; p_teacher!=NULL; p_teacher=p_teacher->next)
    {
        if(strcmp(p_teacher->name, input_name)==0)
        {
            printf("\n该教师职称为：%s\n",p_teacher->rank);        //查询到该教师输出职称
            break;                                                 //并跳出循环，此时p_teacher不为NULL
        }
    }
    //p_teacher为NULL时，说明不存在该教师
    if(p_teacher==NULL)
        ShowModule(plabel_name1, 2);
    if(p_teacher!=NULL)
    {
        printf("\n查询成功！按任意键继续...");
        getchar();  getchar();
    }
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: QuerryClassroom
 * 函数功能: 查询教室信息
 * 输入参数: 教学楼与教室名称
 * 输出参数: 无
 * 返 回 值: true
 */
int QueryClassroom(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：教室容量查询",
                           "确认"
                          };
    char *plabel_name1[] = {"该教室不存在！",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_building[20], input_classroom[20];
    CLASSROOM_NAME *p_classsroom;
    int i;
    int flag=0;

    printf("请输入要查询的教室所在楼栋：");
    scanf("%s",input_building);
    printf("请输入要查询的教室名称：");
    scanf("%s",input_classroom);
    //查询对应的楼栋
    for(i=0; i<g_classroom.length; ++i)
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
        {
            flag=1;
            break;
        }
    }
    //找到对应楼栋
    if(flag==1)
    {
        for(p_classsroom=g_classroom.elem[i].head; p_classsroom!=NULL; p_classsroom=p_classsroom->next)
        {
            if(strcmp(p_classsroom->classroom, input_classroom)==0)
            {
                printf("\n该教室容量为：%d\n",p_classsroom->number);
                break;
            }
        }
        //输入提示信息
        if(p_classsroom!=NULL)
        {
            printf("\n查询成功！按任意键继续...");
            getchar(); getchar();
        }
        else
            ShowModule(plabel_name1, 2);

    }
    //没找到对应的楼栋
    else
        ShowModule(plabel_name1, 2);
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: QuerryClass
 * 函数功能: 查询班级信息
 * 输入参数: 班级名称 专业名称
 * 输出参数: 无
 * 返 回 值: true
 */
int QueryClass(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：班级人数查询",
                           "确认"
                          };
    char *plabel_name1[] = {"该班级不存在！",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_faculty[40];
    int input_class;
    CLASS_INFO *p_class;
    int i;
    int flag=0;

    printf("请输入查询的班级所在专业：");
    scanf("%s",input_faculty);
    printf("请输入查询的班级的序号：");
    scanf("%d",&input_class);
    //查找所在专业
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(g_class.elem[i].faculty, input_faculty)==0)
        {
            flag=1;
            break;
        }
    }
    //找到对应的专业
    if(flag==1)
    {               //遍历该专业的班级查找该班级
        for(p_class=g_class.elem[i].head; p_class!=NULL; p_class=p_class->next)
        {           //找到该班级时，输出人数，并跳出循环
            if(p_class->class_name==input_class)
            {
                printf("\n该班级人数为：%d\n",p_class->student_number);
                break;
            }
        }
        if(p_class!=NULL)           //该班级存在时，p_class不为NULL
        {
            printf("\n查询成功！按任意键继续...\n");
            getchar();  getchar();
        }
        else                        //该班级不存在
            ShowModule(plabel_name1, 2);
    }
    //不存在该班级对应的专业
    else
        ShowModule(plabel_name1, 2);
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: QuerryCourse
 * 函数功能: 查询课程信息
 * 输入参数: 课程名称
 * 输出参数: 无
 * 返 回 值: true
 */
int QueryCourse(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：课程信息查询",
                           "确认"
                          };
    char *plabel_name1[] = {"该课程不存在！",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    COURSE_GRAPH input_graph;
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class, *p;
    COURSE_INFO_GRAPH *p_course;
    int i;
    char input_course[50];
    int flag=0;

    printf("请输入要查询的课程所在专业名称：");
    scanf("%s",input_graph.faculty);
    printf("请输入要查询的课程的年份：");
    scanf("%d",&(input_graph.year));
    printf("请输入要查询的课程春秋季：（1为春2为秋）");
    scanf("%d",&(input_graph.time));
    printf("请输入要查询的课程的年级：（例：2016）");
    scanf("%d",&(input_graph.grade));
    printf("请输入该课程名称：");
    scanf("%s",input_course);
    //查找对应的专业
    for(p_graph=gp_head; p_graph!=NULL; p_graph=p_graph->next)
    {
        if(strcmp(p_graph->faculty,input_graph.faculty)==0 &&
           p_graph->grade==input_graph.grade &&
           p_graph->year==input_graph.year &&
           p_graph->time==input_graph.time)
        {
            flag=1;
            break;
        }
    }
    //找到该专业
    if(flag==1)
    {


            for(p_course=p_graph->next_course; p_course!=NULL; p_course=p_course->next)
            {
                if(strcmp(p_course->course_name, input_course)==0)
                {
                    printf("\n%s\n\n ",p_graph->faculty);
                    for(p_class=p_course->next_class; p_class; )
                    {
                        for(i=0; i<p_class->class_number; ++i)
                        printf("%d班 ",p_class->class_name[i]);
                        printf("任课教师为:\n");
                        for(i=0;i<p_class->teacher_number;++i)
                            printf("%s  ",p_class->teacher[i].teacher);
                        printf("\n\n");
                        flag=2;
                        for(p=p_class->next; p; p=p->next)
                        {
                            i=0;
                            if(p->class_number==p_class->class_number)
                            {
                                for(i=0; i<p_class->class_number; ++i)
                                {
                                    if(p_class->class_name[i]!=p->class_name[i])
                                        break;
                                }
                            }
                            if(i!=p_class->class_number) break;

                        }
                        p_class=p;
                    }
                }
            }
            if(flag==2)
            {
                printf("\n查询成功！按任意键继续...");
                getchar();  getchar();
            }
            else
                ShowModule(plabel_name1, 2);

    }
    else
        ShowModule(plabel_name1, 2);
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: QuerryClassGraph
 * 函数功能: 查询课堂信息
 * 输入参数: 课堂对应的具体时间
 * 输出参数: 无
 * 返 回 值: true
 */
int QueryClassGraph(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：课堂信息查询",
                           "确认"
                          };
    char *plabel_name1[] = {"该课堂不存在！",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    COURSE_GRAPH *p_graph;
    COURSE_GRAPH input_graph;
    int i, j;
    int class_number, class_name[5];
    int flag=0;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class;
    char input_course[50];
    //课堂信息输入
    printf("请输入要查询的课堂所在专业：");
    scanf("%s",input_graph.faculty);
    printf("请输入要查询的课堂的年份：");
    scanf("%d",&(input_graph.year));
    printf("请输入要查询的课堂春秋季：（1为春2为秋）");
    scanf("%d",&(input_graph.time));
    printf("请输入要查询的课堂的年级：（例：2016）");
    scanf("%d",&(input_graph.grade));
    printf("请输入该合班数：");
    scanf("%d",&class_number);
    printf("请输入各个班级号：");
    for(i=0; i<class_number; ++i)
        scanf("%d",class_name+i);
    printf("请输入该课堂的课程名称：");
    scanf("%s",input_course);
    //printf("请输入要查询的课堂第几周到第几周，周几，第几节到第几节：");
    //scanf("%d %d %d %d %d",&(input_time.week_prior),&(input_time.week_next),
    //      &(input_time.day),&(input_time.course_prior),&(input_time.course_next) );
    ClearScreen();  ShowMenu();
    printf("该课堂信息为：\n");
    //遍历查找对应的专业，找到令flag为1，且跳出循环
    for(p_graph=gp_head; p_graph!=NULL; p_graph=p_graph->next)
    {
        if(strcmp(p_graph->faculty,input_graph.faculty)==0 &&
           p_graph->grade==input_graph.grade &&
           p_graph->year==input_graph.year &&
           p_graph->time==input_graph.time)
        {
            flag=1;
            break;
        }
    }
    //找到对应的专业
    if(flag==1)
    {   //查找对应的课程,找到令flag为2，跳出循环
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            if(strcmp(p_course->course_name, input_course)==0)
            {
               flag=2;
               break;
            }
        }
        //找到对应的课程
        if(flag==2)
        {
            for(p_class=p_course->next_class; p_class; p_class=p_class->next)
            {
                i=0;
                if(p_class->class_number==class_number)
                {
                    for(i=0; i<class_number; ++i)
                    if(p_class->class_name[i]!=class_name[i])
                        break;
                }
                if(i==class_number)
                {
                    printf("\n第%2d周到第%2d周    星期%2d  第%2d节到第%2d节\n",p_class->week_prior
                           ,p_class->week_next,p_class->day,p_class->course_prior,p_class->course_next);
                    printf("\n教师：");
                    for(j=0;j<p_class->teacher_number; ++j)
                        printf("%s ",p_class->teacher[j].teacher);
                    printf("\n地点：%s %s\n",p_class->building,p_class->classroom);
                }
            }
        }
        else
            ShowModule(plabel_name1, 2);
    }
    else
        ShowModule(plabel_name1, 2);
    printf("\n\n按任意键继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * 函数名称: QuerryFreeClassroom
 * 函数功能: 查询空闲教室
 * 输入参数: 楼栋名称 具体时间
 * 输出参数: 无
 * 返 回 值: true
 */
int QueryFreeClassroom(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：空闲教室查询",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_building[20];
    int *base;
    int week,flag;
    int day;
    int classroom_number,i,j,z,k,number;
    COURSE_GRAPH input_faculty;
    CLASS_INFO_GRAPH *p_class;
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    CLASSROOM_NAME *p_classroom;

    printf("请输入要查询空闲教室的楼栋：");
    scanf("%s",input_building);
    printf("请输入要查询空闲教室的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要查询空闲教室的春秋季（1春2秋）：");
    scanf("%d",&(input_faculty.time));
    printf("请输入要查询空闲教室的时间：第几周 周几 ");
    scanf("%d %d",&week,&day);
    //查找对应的教学楼
    for(i=0;i<g_classroom.length;++i)
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
            break;
    }
    if(i<g_classroom.length)    //找到教学楼
    {
        for(k=1; k<12; k=k+2)
        {
        classroom_number=g_classroom.elem[i].classroom_number;      // 该楼栋教室数
        base=(int *)malloc(classroom_number*sizeof(int));           //为每个教室分配一个地址
        for(j=0;j<classroom_number;++j)                             //将分配的内存全部初始化为1，表示未使用
            *(base+j)=0;
        for(p_graph=gp_head; p_graph!=NULL; p_graph=p_graph->next)  //遍历对应时间的每个课堂
        {                                                           //将被占用的教室为置为 1
            if(p_graph->year==input_faculty.year &&
               p_graph->time==input_faculty.time)

                for(p_course=p_graph->next_course; p_course!=NULL; p_course=p_course->next)
                {
                    for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                    {
                        flag=0;
                        if(p_class->day==day &&
                           p_class->course_prior==k &&
                           p_class->course_next==k+1 &&
                           strcmp(p_class->building, input_building)==0)
                        {
                            for(j=p_class->week_prior; j<=p_class->week_next; ++j)
                            {
                                if(j==week)
                                {
                                    flag=1;
                                    break;
                                }
                            }
                        }
                        if(flag==1)
                        {
                            for(number=0,p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
                            {
                                if(strcmp(p_classroom->classroom, p_class->classroom)==0)
                                    break;
                                ++number;
                            }
                            *(base+number)=1;
                        }
                    }
                }

        }
        printf("\n\n第%d %d节空闲教室为：\n",k,(k+1));
        for(z=0,j=0,p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
        {
            if(*(base+z)==0)                    //对应为0表示为占用
            {
                if(j%6==0)
                    printf("\n");
                printf("%s ",p_classroom->classroom);
                ++j;
            }
            ++z;
        }
        }

    }
    else
        printf("\n该楼栋不存在！\n");
    printf("\n\n按任意键继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * 函数名称: SearchCourseByTeacher
 * 函数功能: 按教师检索课堂信息
 * 输入参数: 教师名称
 * 输出参数: 无
 * 返 回 值: true
 */
int SearchCourseByTeacher(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：按教师检索课堂",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_teacher[20];
    int i,flag,flag1;
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class, *p;
    COURSE_INFO_GRAPH *p_course;

    printf("请输入要检索的教师名称：");
    scanf("%s",input_teacher);
    //遍历每个课堂，如果为对应的教师 输出
    printf("\n该教师所任课堂为：\n");
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag=0;
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            for(p_class=p_course->next_class; p_class; )
            {
                flag1=0;
                for(i=0; i<p_class->teacher_number; ++i)
                {
                    if(strcmp(p_class->teacher[i].teacher, input_teacher)==0)
                    {
                        flag1=1;
                        break;
                    }
                }
                if(flag1==1)
                {
                    if(flag==0)
                    {
                        printf("\n%d年 %d级 ",p_graph->year,p_graph->grade);
                        if(p_graph->time==1)    printf("春季\n");
                        else    printf("秋季\n");
                        flag=1;
                    }
                    printf("\n");
                    for(i=0;i<p_class->class_number;++i)
                        printf("%d班 ",p_class->class_name[i]);
                    printf(" %s",p_course->course_name);
                    printf("\n");
                    printf("%2d周到%2d周   星期%d    第%2d节到第%2d节 %s  %s\n",p_class->week_prior,p_class->week_next
                        ,p_class->day,p_class->course_prior,p_class->course_next,p_class->building,p_class->classroom);
                    for(p=p_class->next; p; p=p->next)
                    {
                        i=0;
                        if(p->class_number==p_class->class_number)
                        {
                            for(i=0; i<p_class->class_number; ++i)
                            {
                                if(p_class->class_name[i]!=p->class_name[i])
                                    break;
                            }
                        }
                        if(i!=p_class->class_number) break;
                        printf("%2d周到%2d周   星期%d    第%2d节到第%2d节 %s  %s\n",p->week_prior,p->week_next
                        ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                    }
                    p_class=p;
                }
                else
                    p_class=p_class->next;
            }

        }//课程
    }//专业
    printf("\n\n按任意键继续...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: SearchCourseByClass
 * 函数功能: 按班级检索课堂信息
 * 输入参数: 班级名称
 * 输出参数: 无
 * 返 回 值: true
 */
int SearchCourseByClass(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：按班级检索课堂",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    int input_class;
    char input_faculty[40];
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class;
    int i, flag, grade;
    COURSE_INFO_GRAPH *p_course;

    printf("请输入该班级所在专业：");
    scanf("%s",input_faculty);
    printf("请输入要检索的班级序号：");
    scanf("%d",&input_class);
    printf("请输入该班级的年级：");
    scanf("%d",&grade);
    printf("该班级课堂为：\n");
    //遍历每个课堂如果为对应的班级 输出
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag=0;
        if(strcmp(p_graph->faculty,input_faculty)==0 &&
           p_graph->grade==grade)
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            if(flag==0)
            {
                printf("\n%d年 ",p_graph->year);
                if(p_graph->time==1)    printf("春季：\n");
                else    printf("秋季：\n");
            }
            printf("\n%s\n\n",p_course->course_name);
            for(p_class=p_course->next_class; p_class; p_class=p_class->next)
            for(i=0; i<p_class->class_number; ++i)
            {
                if(p_class->class_name[i]==input_class)
                {

                    printf("第%2d周到第%2d周 星期%2d 第%2d节到第%2d节",p_class->week_prior,p_class->week_next,
                            p_class->day,p_class->course_prior,p_class->course_next);
                    printf(" %s %s\n",p_class->building,p_class->classroom);

                    flag=1;

                }
            }
        }//班级
    }//专业

    printf("\n\n按任意键继续...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: SearchCourseByCourse
 * 函数功能: 按课程检索课堂信息
 * 输入参数: 课程名称
 * 输出参数: 无
 * 返 回 值: true
 */
int SearchCourseByCourse(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：按课程检索课堂",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_course[50];
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class, *p;
    int i,flag;
    printf("请输入要检索的课程名称：");
    scanf("%s",input_course);
    //printf("请输入该课程的专业全称：");
    //scanf("%s",input_faculty);
    printf("\n该课程课堂为：\n");
    //遍历每个课程，找到该课程 输出课堂
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag=0;
        //if(strcmp(p_graph->faculty, input_faculty)==0)

        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            if(strcmp(p_course->course_name, input_course)==0)
            {
                /*for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                {

                    if(flag==0)
                    {
                        printf("\n%d年 ",p_graph->year);
                        if(p_graph->time==1)    printf("春季：\n");
                        else    printf("秋季：\n");
                        printf(" %s",p_graph->faculty);
                        flag=1;
                    }
                    printf("\n");
                    for(i=0; i<p_class->class_number; ++i)
                    {
                        printf("%d班",p_class->class_name[i]);
                    }
                    printf("\n");

                        printf("第%2d周到第%2d周 星期%2d 第%2d节到第%2d节",p_class->week_prior,p_class->week_next
                               ,p_class->day,p_class->course_prior,p_class->course_next);
                        printf(" %s %s\n",p_class->building,p_class->classroom);

                }*/
                for(p_class=p_course->next_class; p_class;  )
            {
                if(flag==0)
                    {
                        printf("\n%d年 ",p_graph->year);
                        if(p_graph->time==1)    printf("春季：\n");
                        else    printf("秋季：\n");
                        printf(" %s",p_graph->faculty);
                        flag=1;
                    }
                printf("\n");
                for(i=0;i<p_class->class_number;++i)
                    printf("%d班 ",p_class->class_name[i]);
                for(i=0; i<p_class->teacher_number; ++i)
                    printf(" %s",p_class->teacher[i].teacher);
                printf("\n");
                printf("%2d周到%2d周   星期%d    第%2d节到第%2d节 %s  %s\n",p_class->week_prior,p_class->week_next
                    ,p_class->day,p_class->course_prior,p_class->course_next,p_class->building,p_class->classroom);
                for(p=p_class->next; p; p=p->next)
                {
                    i=0;
                    if(p->class_number==p_class->class_number)
                    {
                        for(i=0; i<p_class->class_number; ++i)
                        {
                            if(p_class->class_name[i]!=p->class_name[i])
                                break;
                        }
                    }
                    if(i!=p_class->class_number) break;
                    printf("%2d周到%2d周   星期%d    第%2d节到第%2d节 %s  %s\n",p->week_prior,p->week_next
                    ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                }
                p_class=p;
            }
            }
        }//课程

    }//专业
    printf("\n\n按任意键继续...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: SearchCourseByClassroom
 * 函数功能: 按教室检索课堂信息
 * 输入参数: 教室名称
 * 输出参数: 无
 * 返 回 值: true
 */
int SearchCourseByClassroom(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：按教室检索课堂",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_classroom[20], input_building[20];
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class, *p;
    int i,flag, flag1;
    printf("请输入要检索的教室所在楼栋：");
    scanf("%s",input_building);
    printf("请输入要检索的教室名称：");
    scanf("%s",input_classroom);
    printf("\n该教室课堂为：\n");
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag1=0;

            for(p_course=p_graph->next_course,flag=0; p_course; p_course=p_course->next,flag=0)
            {
               for(p_class=p_course->next_class; p_class; )
               {    //如果课堂满足要求 输出信息
                   if(strcmp(p_class->building,input_building)==0&&
                      strcmp(p_class->classroom,input_classroom)==0)
                    {
                        if(flag1==0)
                        {       //flag1用于控制 专业 年级的输出
                            printf("\n%d年 %d级 ",p_graph->year,p_graph->grade);
                            printf(" %s ",p_graph->faculty);
                            if(p_graph->time==1)    printf("春季：\n");
                            else    printf("秋季：\n");
                            flag1=1;
                        }
                        if(flag==0)     //flag用于控制课程名称输出
                        {
                            printf("\n%s\n\n",p_course->course_name);
                        }
                        for(i=0; i<p_class->class_number; ++i)
                                printf("%d班",p_class->class_name[i]);
                        printf("\n");
                        printf("%2d周到%2d周   星期%2d   第%2d节到第%2d节",p_class->week_prior,p_class->week_next
                               ,p_class->day,p_class->course_prior,p_class->course_next);
                        printf(" %s %s\n",p_class->building,p_class->classroom);
                        flag=1;
                        for(p=p_class->next; p; p=p->next)
                        {           //该循环用于输出所有该班级该课程的课堂情况 且只输出一次合班
                            i=0;
                            if(p->class_number==p_class->class_number)
                            {
                                for(i=0; i<p_class->class_number; ++i)
                                {
                                    if(p_class->class_name[i]!=p->class_name[i])
                                        break;
                                }
                            }
                            if(i!=p_class->class_number) break;
                            if(strcmp(p->building,input_building)==0&&
                                strcmp(p->classroom,input_classroom)==0)
                            printf("%2d周到%2d周   星期%2d   第%2d节到第%2d节 %s %s\n",p->week_prior,p->week_next
                            ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                        }
                        p_class=p;
                    }
                    else
                        p_class=p_class->next;
               }
            }

    }
    printf("\n\n按任意键继续...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: SearchCourseByTime
 * 函数功能: 按时间检索课堂信息
 * 输入参数: 具体课堂时间
 * 输出参数: 无
 * 返 回 值: true
 */
int SearchCourseByTime(void)
{
    char *plabel_name[] = {"主菜单项：数据查询",
                           "子菜单项：按时间检索课堂",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    COURSE_GRAPH input_faculty;
    CLASS_INFO_GRAPH *p_class, input_time;
    int i,j,flag;
    int week;
    printf("请输入要检索课堂的时间年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要检索课堂的时间春秋季：");
    scanf("%d",&(input_faculty.time));
    printf("请输入要检索课堂的时间的周次：");
    scanf("%d",&(week));
    printf("请输入要检索课堂的时间周几：");
    scanf("%d",&(input_time.day));
    printf("请输入要检索课堂的时间第几节到第几节：");
    scanf("%d %d",&(input_time.course_prior), &(input_time.course_next));

    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag=0;
        if(p_graph->year==input_faculty.year &&
           p_graph->time==input_faculty.time )

            for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
            {
                for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                {       //如果课堂满足情况 则输出该课堂信息
                    if(p_class->course_next==input_time.course_next &&
                       p_class->day==input_time.day &&
                       p_class->course_prior==input_time.course_prior)
                    {
                        for(j=p_class->week_prior; j<=p_class->week_next; ++j)
                        {
                            if(j==week)
                                break;
                        }
                        if(j<=p_class->week_next)
                        {
                            if(flag==0)
                                printf("\n%s %d级\n",p_graph->faculty,p_graph->grade);
                            for(i=0;i<p_class->class_number;++i)
                                printf("%d班",p_class->class_name[i]);
                            printf(" %s %s %s\n"
                                   ,p_course->course_name,p_class->building,p_class->classroom);
                            flag=1;
                        }
                    }
                }
            }//课程

    }//专业
    printf("\n\n按任意键继续...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * 函数名称: AnalysisUsingRate
 * 函数功能: 教室利用率分析
 * 输入参数: 教学楼名称 分析时间
 * 输出参数: 无
 * 返 回 值: true
 */
int AnalysisUsingRate(void)
{
    char *plabel_name[] = {"主菜单项：数据分析",
                           "子菜单项：教室利用率分析",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_building[20];
    float rate;
    int classroom_number,i,j,number,a;
    COURSE_GRAPH input_faculty;
    CLASS_INFO_GRAPH *p_class,input_time;
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    CLASSROOM_NAME *p_classroom;
    int *base;
    int week;
    number=0;

    printf("请输入要分析教室利用率的楼栋：");
    scanf("%s",input_building);
    printf("请输入要分析教室利用率的年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要分析教室利用率的春秋季（1为春2为秋）:");
    scanf("%d",&(input_faculty.time));
    printf("请输入要分析教室利用率的时间：第几周 周几 第几节到第几节课；");
    scanf("%d %d %d %d",&(week),&(input_time.day),&(input_time.course_prior),&(input_time.course_next));

    for(i=0;i<g_classroom.length;++i)
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
            break;
    }
    if(i<g_classroom.length)
    {
        classroom_number=g_classroom.elem[i].classroom_number;      // 该楼栋教室数
        base=(int *)malloc(classroom_number*sizeof(int));           //每个教室一个位置，1代表使用
        for(a=0;a<classroom_number;++a)
            *(base+a)=0;
        for(p_graph=gp_head; p_graph!=NULL; p_graph=p_graph->next)
        {
            if(input_faculty.year==p_graph->year &&
               input_faculty.time==p_graph->time)

                for(p_course=p_graph->next_course; p_course!=NULL; p_course=p_course->next)
                {
                    for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                    {
                        j=0;        //判断该课堂是否 满足要求
                        if(p_class->course_next==input_time.course_next &&
                           p_class->day==input_time.day &&
                           p_class->course_prior==input_time.course_prior &&
                           strcmp(p_class->building, input_building)==0)
                        {
                            for(j=p_class->week_prior; j<p_class->week_next; ++j)
                            {
                                if(j==week)
                                break;
                            }
                        }           //该课堂满足将对应教室记录
                        if(j==week)
                        {
                            for(a=0,p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
                            {
                                if(strcmp(p_classroom->classroom, p_class->classroom)==0)
                                    *(base+a)=1;            //令该教室对应的位置标记为1表示已使用
                                ++a;
                            }
                        }
                    }
                }

        }
        //遍历标记地址，查找使用的教室数
        for(number=0,a=0;a<classroom_number;++a)
        {
            if(*(base+a)==1)
                ++number;
        }
        rate=(float)number/(float)classroom_number;
        printf("\n共有教室%d  使用%d\n",classroom_number,number);
        printf("\n该教学楼在该时段教室利用率为：%f",rate);
    }
    else
        printf("\n该楼栋不存在！\n");
    printf("\n\n按任意键继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * 函数名称: AnalysisCourseByTeacher
 * 函数功能: 教师承担课堂合理性分析
 * 输入参数: 教师名称
 * 输出参数: 无
 * 返 回 值: true
 */
int AnalysisCourseByTeacher(void)
{
    char *plabel_name[] = {"主菜单项：数据分析",
                           "子菜单项：教师承担课堂合理性分析",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    int class_time[1700];
    char input_teacher[15];
    char building[20],classroom[20];
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class;
    int i, count,j,k,flag1;
    int flag=0;
    int week,day,part;
    COURSE_INFO_GRAPH *p_course;
    for(i=0;i<1700;++i)         //表示一个学期的所有课堂时间
        class_time[i]=0;
    printf("请输入要分析承担课堂合理性的教师名称：");
    scanf("%s",input_teacher);
    printf("请输入要分析的课堂年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要分析的课堂年级：");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要分析的课堂的春秋季（1为春2为秋）：");
    scanf("%d",&(input_faculty.time));

    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        if(p_graph->year==input_faculty.year &&
           p_graph->grade==input_faculty.grade &&
           p_graph->time==input_faculty.time)

            for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
            {
                for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                for(i=0; i<p_class->teacher_number; ++i)
                if(strcmp(p_class->teacher[i].teacher, input_teacher)==0)
                {
                                //将该教师的课堂每个时间写入时间数组
                        for(j=p_class->week_prior; j<=p_class->week_next; ++j)
                        {
                            count=(j-1)*84+(p_class->day-1)*12+p_class->course_prior;
                            ++class_time[count];
                            if(class_time[count]>1) flag=1;
                            ++count;
                            ++class_time[count];
                            if(class_time[count]>1) flag=1;
                        }

                }
            }

    }

    if(flag==0)
        printf("\n该教师在该学期该年级的课堂承担合理！");
    else
    {               //判断不合理的时间是否时不同合班在同一地点上课
        for(k=0; k<1700; ++k)
        {
            flag1=0;
            if(class_time[k]>1)
            for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
            {
            if(p_graph->year==input_faculty.year &&
            p_graph->grade==input_faculty.grade &&
            p_graph->time==input_faculty.time)
                    //该专业课表满足要求
            for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
            {
                for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                for(i=0; i<p_class->teacher_number; ++i)
                if(strcmp(p_class->teacher[i].teacher, input_teacher)==0)
                {           //如果找到该教师

                        for(j=p_class->week_prior; j<=p_class->week_next; ++j)
                        {
                            count=(j-1)*84+(p_class->day-1)*12+p_class->course_prior;
                            if(count==k)
                            {
                                if(flag1==0)
                                {
                                    strcpy(building,p_class->building);
                                    strcpy(classroom,p_class->classroom);
                                }
                                if(flag1==1)
                                {   //如果是不同合班 同一地点 则时间数组对应减一
                                    if(strcmp(p_class->building,building)==0 &&
                                       strcmp(p_class->classroom,classroom)==0)
                                    {
                                        --(class_time[k]);
                                        --(class_time[k+1]);
                                    }
                                }
                                flag1=1;
                            }
                        }

                }
            }

            }
        }

    printf("\n该教师在该学期该年级的课堂承担在以下时间不合理：\n");
        for(i=0;i<1700;++i)
        {
            if(class_time[i]>1)
            {
                week=i/84+1;
                day=(i%84)/12+1;
                part=(i%84)%12;
                if(part==0)
                {
                    --day;
                    part=12;
                }
                printf("第%d周 星期%d 第%d节\n",week,day,part);
            }
        }
    }
    printf("\n\n按任意键继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * 函数名称: AnalysisCourseByClass
 * 函数功能: 班级参与课堂合理性分析
 * 输入参数: 班级名称
 * 输出参数: 无
 * 返 回 值: true
 */
int AnalysisCourseByClass(void)
{
    char *plabel_name[] = {"主菜单项：数据分析",
                           "子菜单项：班级参与课堂合理性分析",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    int class_time[1700];
    int input_class;
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_graph;
    int i, count,j;
    int flag=0;
    int week,day,part;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class;
    for(i=0;i<1700;++i)     //用于存放每个时间上课情况
        class_time[i]=0;
    printf("请输入要分析的班级的专业：");
    scanf("%s",input_faculty.faculty);
    printf("请输入要分析参与课堂合理性的班级序号：");
    scanf("%d",&input_class);
    printf("请输入要分析的课堂年份：");
    scanf("%d",&(input_faculty.year));
    printf("请输入要分析的课堂年级：");
    scanf("%d",&(input_faculty.grade));
    printf("请输入要分析的课堂的春秋季（1为春2为秋）：");
    scanf("%d",&(input_faculty.time));

    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        if(p_graph->year==input_faculty.year &&
           p_graph->grade==input_faculty.grade &&
           p_graph->time==input_faculty.time &&
           strcmp(p_graph->faculty, input_faculty.faculty)==0)
            //满足专业课表要求
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            for(p_class=p_course->next_class; p_class; p_class=p_class->next)
            {
                for(i=0; i<p_class->class_number; ++i)
                if(p_class->class_name[i]==input_class)     //如果是要分析的班级，将课堂时间录入数组
                for(j=p_class->week_prior; j<=p_class->week_next;++j)
                {
                        count=(j-1)*84+(p_class->day-1)*12+p_class->course_prior;
                        ++class_time[count];
                        if(class_time[count]>1)    flag=1;      //flag为1表示存在不合理
                        ++count;
                        ++class_time[count];
                        if(class_time[count]>1)    flag=1;
                }
            }
        }

    }
    if(flag==0)
        printf("\n该班级在该学期的课堂参与合理！");
    else
    {
        printf("\n该班级在该学期的课堂参与在以下时间不合理：\n");
        for(i=0;i<1700;++i)
        {
            if(class_time[i]>1)
            {
                week=i/84+1;
                day=(i%84)/12+1;
                part=(i%84)%12;
                if(part==0)
                {
                    --day;
                    part=12;
                }
                printf("第%d周 星期%d 第%d节\n",week,day,part);
            }
        }
    }
    printf("\n\n按任意键继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * 函数名称: AnalysisEnergy
 * 函数功能: 能效分析
 * 输入参数: 教室名称 分析时间
 * 输出参数: 无
 * 返 回 值: true
 */
int AnalysisEnergy(void)
{
    char *plabel_name[] = {"主菜单项：数据分析",
                           "子菜单项：能效分析",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    char input_building[20], input_classroom[20];
    CLASSROOM_NAME *p_classroom;
    int classroom_capacity, i, number, z, j;
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_faculty;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO *p_name;
    int week;
    CLASS_INFO_GRAPH *p_class,input_time;

    printf("请输入进行能效分析的教室楼栋名称：");
    scanf("%s",input_building);
    printf("请输入进行能效分析的教室：");
    scanf("%s",input_classroom);
    printf("请输入进行能效分析的时间：\n年份  春秋季（1为春2为秋）  周次  星期几  第几节课到第几节课：\n");
    scanf("%d %d %d %d %d %d",&(input_faculty.year),&(input_faculty.time),
          &(week),&(input_time.day),&(input_time.course_prior),&(input_time.course_next));
    classroom_capacity=0;
    number=0;
    for(i=0; i<g_classroom.length; ++i)         //遍历教室信息，查找该教室
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
        {
            for(p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
            if(strcmp(p_classroom->classroom, input_classroom)==0)
            {
                classroom_capacity=p_classroom->number;     //教室容量
                break;
            }
        }
    }

    if(classroom_capacity==0)
        printf("\n该教室不存在！\n");
    else
    {                             //专业循环
        for(p_faculty=gp_head; p_faculty; p_faculty=p_faculty->next)
        if(p_faculty->year==input_faculty.year &&
           p_faculty->time==input_faculty.time)//是该专业课表时
        {               //课程循环
                for(p_course=p_faculty->next_course; p_course; p_course=p_course->next)
                    for(p_class=p_course->next_class; p_class; p_class=p_class->next)   //课堂循环
                    {
                        z=0;
                        if(p_class->course_next==input_time.course_next &&
                           p_class->day==input_time.day &&
                           p_class->course_prior==input_time.course_prior &&
                           strcmp(p_class->building, input_building)==0 &&
                           strcmp(p_class->classroom, input_classroom)==0)
                        {               //判断该课堂是否满足
                            for(z=p_class->week_prior; z<p_class->week_next; ++z)
                            {
                                if(z==week)
                                    break;
                            }
                        }
                        if(z==week)         //课堂满足要求  将在该课堂的所有班级人数相加
                        {
                            for(i=0; i<p_class->class_number; ++i)
                            for(j=0;j<g_class.length;++j)
                            {
                                for(p_name=g_class.elem[j].head; p_name; p_name=p_name->next)
                                {
                                    if(p_class->class_name[i]==p_name->class_name &&
                                       strcmp(p_faculty->faculty, g_class.elem[j].faculty)==0)
                                    {
                                        number=number+p_name->student_number;
                                    }
                                }
                            }
                        }
                    }
        }
        printf("\n该教室共%d位置，使用%d个\n",classroom_capacity,number);
        printf("\n该教室使用率为：%f\n",(float)number/(float)classroom_capacity);
    }
    printf("\n\n按任意键继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * 函数名称: TraversalGraph
 * 函数功能: 遍历课表
 * 输入参数: 无
 * 输出参数: 课表信息
 * 返 回 值: true
 */
int TraversalGraph(void)
{
    char *plabel_name[] = {"主菜单项：遍历数据",
                           "子菜单项：课表遍历",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class, *p;
    COURSE_INFO_GRAPH *p_course;
    int i;
    //int number=0;
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        printf("\n%d ",p_graph->year);
        if(p_graph->time==1)    printf("春季 ");
        else    printf("秋季 ");
        printf("%s %d级\n",p_graph->faculty,p_graph->grade);


        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            printf("\n%s \n",p_course->course_name);

            for(p_class=p_course->next_class; p_class;  )
            {
                printf("\n");
                //++number;
                for(i=0;i<p_class->class_number;++i)
                    printf("%d班 ",p_class->class_name[i]);      //  输出合班情况
                for(i=0; i<p_class->teacher_number; ++i)
                    printf(" %s",p_class->teacher[i].teacher);      //教师情况
                printf("\n");                                   //具体时间
                printf("%2d周到%2d周   星期%d    第%2d节到第%2d节 %s  %s\n",p_class->week_prior,p_class->week_next
                    ,p_class->day,p_class->course_prior,p_class->course_next,p_class->building,p_class->classroom);
                for(p=p_class->next; p; p=p->next)          //该循环用于输出所有该班级该课程下的课堂
                {
                    i=0;
                    if(p->class_number==p_class->class_number)
                    {                       //判断是否是该课堂
                        for(i=0; i<p_class->class_number; ++i)
                        {
                            if(p_class->class_name[i]!=p->class_name[i])
                                break;
                        }
                    }
                    if(i!=p_class->class_number) break;
                    printf("%2d周到%2d周   星期%d    第%2d节到第%2d节 %s  %s\n",p->week_prior,p->week_next
                    ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                }
                p_class=p;
            }
        }


    }
    //printf("\n课堂数为：%d\n",number);
    printf("\n\n按回车继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * 函数名称: TraversalClass
 * 函数功能: 遍历班级
 * 输入参数: 无
 * 输出参数: 班级信息
 * 返 回 值: true
 */
int TraversalClass(void)
{
    char *plabel_name[] = {"主菜单项：遍历数据",
                           "子菜单项：班级遍历",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    CLASS_INFO *p_class;
    int i;

    for(i=0; i<g_class.length; ++i)         //专业遍历
    {
        printf("\n%s\n\n",g_class.elem[i].faculty);
        //专业班级遍历
        for(p_class=g_class.elem[i].head; p_class; p_class=p_class->next)
        {
            printf("%d班 %d人\n",p_class->class_name,p_class->student_number);
        }
    }
    printf("\n\n按回车继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * 函数名称: TraversalClassroom
 * 函数功能: 遍历教室
 * 输入参数: 无
 * 输出参数: 教室信息
 * 返 回 值: true
 */
int TraversalClassroom(void)
{
    char *plabel_name[] = {"主菜单项：遍历数据",
                           "子菜单项：教室遍历",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    int i;
    CLASSROOM_NAME *p_classroom;
    for(i=0; i<g_classroom.length; ++i)         //遍历教学楼
    {
        printf("\n%s\n\n",g_classroom.elem[i].classroom_building);
        //遍历教学楼的所有教室
        for(p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
        {
            printf("%s  容量：%d\n",p_classroom->classroom,p_classroom->number);
        }
    }
    printf("\n\n按回车继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * 函数名称: TraversalTeacher
 * 函数功能: 遍历教师
 * 输入参数: 无
 * 输出参数: 教师信息
 * 返 回 值: true
 */
int TraversalTeacher(void)
{
    char *plabel_name[] = {"主菜单项：遍历数据",
                           "子菜单项：教师遍历",
                           "确认"
                          };
    ShowModule(plabel_name, 3);
    TEACHER_INFO *p_teacher;
    //循环遍历 输出教师信息
    for(p_teacher=gp_teacher; p_teacher; p_teacher=p_teacher->next)
    {
        printf("%-10s %-10s\n",p_teacher->name,p_teacher->rank);
    }
    printf("\n\n按回车继续...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

