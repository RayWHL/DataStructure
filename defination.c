#include "defination.h"

/**
 * ��������: MaintainClassroom_Add
 * ��������: ���ӽ�����Ϣ
 * �������: ��ѧ¥���� �������� ��������
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClassroom_Add(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵����������",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�������ӳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ý����Ѵ��ڣ�",
                           "ȷ��"
                          };
    char *plabel_name3[] = {"�ڴ������",
                           "ȷ��"
                          };
    CLASSROOM_INFO *newbase, *p;
    char building_name[20];
    int i;
    int flag=0;
    CLASSROOM_NAME *name, *p_name;

    name=(CLASSROOM_NAME *)malloc(sizeof(CLASSROOM_NAME));

    printf("������������������¥�����ƣ�");
    scanf("%s",building_name);
    //���Ҷ�Ӧ�Ľ�ѧ¥
    for(i=0;i<g_classroom.length;++i)
    {
        p=g_classroom.elem+i;
        if(strcmp(p->classroom_building,building_name)==0)
        {
            flag=1;
            break;
        }
    }

    printf("������������ƣ�");
    scanf("%s",name->classroom);
    printf("�������������������");
    scanf("%d",&(name->number));
    //�ҵ���Ӧ�Ľ�ѧ¥
    if(flag==1)
    {
        p_name=p->head;
        //���Ҹý����Ƿ��Ѿ�����
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
    //û�ж�Ӧ�Ľ�ѧ¥��������ѧ¥��Ϣ
    if(flag==0)
    {
        //�ڴ����
        if(g_classroom.length>=g_classroom.listsize)
        {
        //�����µ�ַ
            newbase=(CLASSROOM_INFO *)realloc(g_classroom.elem, (g_classroom.listsize+LISTINCREMENT)*sizeof(CLASSROOM_INFO));
            if(!newbase)        //����ʧ��
            {
                ShowModule(plabel_name3, 2);
                return error;
            }
            g_classroom.elem=newbase;                 //�µ�ַ
            g_classroom.listsize=g_classroom.listsize+LISTINCREMENT;        //�޸�����
        }
        p=g_classroom.elem+g_classroom.length;
        strcpy(p->classroom_building, building_name);
        p->head=name;
        name->next=NULL;
        p->classroom_number=1;
        ++g_classroom.length;
        ShowModule(plabel_name1, 2);
    }
    ClearScreen();     //����
    ShowMenu();        //��ʾ�˵�����
    return true;
}

/**
 * ��������: MaintainClassroom_Modify
 * ��������: �޸Ľ�����Ϣ
 * �������: ����¥�� ��������
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClassroom_Modify(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵�������޸�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�����޸ĳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ý��Ҳ����ڣ�",
                           "ȷ��"
                          };

    CLASSROOM_NAME name;
    CLASSROOM_NAME *pname;
    char building_name[20];
    CLASSROOM_INFO *pbuilding;
    int i;
    int flag=0;

    printf("������Ҫ�޸Ľ��ҵ�¥�����ƣ�");
    scanf("%s",building_name);
    printf("������Ҫ�޸ĵĽ������ƣ�");
    scanf("%s",name.classroom);
    //���Ҷ�Ӧ�Ľ�ѧ¥
    for(i=0;i<g_classroom.length;++i)
    {
        pbuilding=g_classroom.elem+i;
        if(strcmp(pbuilding->classroom_building, building_name)==0)
        {
            flag=1;
            break;
        }
    }
    //û�ж�Ӧ�Ľ�ѧ¥
    if(flag==0)
        ShowModule(plabel_name2, 2);
    //�ҵ���Ӧ�Ľ�ѧ¥
    else
    {
        pname=pbuilding->head;
        //����Ҫ�޸ĵĽ���
        for(;pname!=NULL;pname=pname->next)
        {
            if(strcmp(pname->classroom,name.classroom)==0 )
            {
                flag=2;
                break;
            }
        }
        //�ҵ��ý��ң��޸���Ϣ
        if(flag==2)
        {
            printf("�������޸ĺ�Ľ������ƣ�");
            scanf("%s",pname->classroom);
            printf("�������޸ĺ����������");
            scanf("%d",&(pname->number));
            ShowModule(plabel_name1, 2);
        }
        else
        {
            ShowModule(plabel_name2, 2);
        }
    }
    ClearScreen();     //����
    ShowMenu();        //��ʾ�˵�����
    return true;
}

/**
 * ��������: MaintainClassroom_Delete
 * ��������: ɾ��������Ϣ
 * �������: ��ѧ¥���� ��������
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClassroom_Delete(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵������ɾ��",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"����ɾ���ɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ý��Ҳ����ڣ�",
                           "ȷ��"
                          };
    CLASSROOM_NAME name;
    CLASSROOM_NAME *p, *q;
    char building_name[20];
    CLASSROOM_INFO *pbuilding;
    int i;
    int flag=0;

    printf("�������������¥�����ƣ�");
    scanf("%s",building_name);
    printf("������������ƣ�");
    scanf("%s",name.classroom);
    //���Ҷ�Ӧ�Ľ�ѧ¥
    for(i=0; i<g_classroom.length; ++i)
    {
        pbuilding=g_classroom.elem+i;
        if(strcmp(pbuilding->classroom_building, building_name)==0)
        {
            flag=1;
            break;
        }
    }
    //�ҵ���ѧ¥
    if(flag==1)
    {
        q=NULL;
        p=pbuilding->head;
        //�����һ���ڵ��Ӧ�Ľ���Ϊ�ý���
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
            //�������������Ҹý���
            for(p=p->next; p!=NULL; p=p->next)
            {
                if(strcmp(p->classroom, name.classroom)==0)
                {
                    flag=2;
                    q->next=p->next;
                    free(p);
                    --(pbuilding->classroom_number);    //��������һ
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
    ClearScreen();     //����
    ShowMenu();        //��ʾ�˵�����

    return true;
}

/**
 * ��������: MaintainCourseGraph_Add
 * ��������: ���ӿγ���Ϣ
 * �������: �γ̾�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainCourseGraph_Add(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵���γ���Ϣ����",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�γ����ӳɹ���",
                           "ȷ��"
                          };

    char *plabel_name4[] = {"�ÿγ��Ѵ��ڣ�",
                           "ȷ��"
                          };
    COURSE_GRAPH *input_faculty;
    COURSE_GRAPH *p_course;
    COURSE_INFO_GRAPH *newcourse, *p;
    int flag=0;
    //�����ڴ�
    input_faculty=(COURSE_GRAPH *)malloc(sizeof(COURSE_GRAPH));
    newcourse=(COURSE_INFO_GRAPH *)malloc(sizeof(COURSE_INFO_GRAPH));

    printf("������Ҫ���ӵĿγ�����רҵȫ�ƣ�");
    scanf("%s",input_faculty->faculty);
    printf("������Ҫ���ӵĿγ̵���ݣ�");
    scanf("%d",&(input_faculty->year));
    printf("������Ҫ���ӵĿγ̵��꼶����:2016����");
    scanf("%d",&(input_faculty->grade));
    printf("������Ҫ���ӵĿγ̴��＾��1Ϊ�� 2Ϊ�");
    scanf("%d",&(input_faculty->time));
    input_faculty->next=NULL;
    input_faculty->next_course=NULL;

    printf("������ÿγ����ƣ�");
    scanf("%s",newcourse->course_name);

    newcourse->next_class=NULL;
    newcourse->next=NULL;

    /*
    printf("\n����1��ʼ¼���Ͽ�ʱ�䣻����0ֹͣ¼�룺");
    scanf("%d",&z);
    //��������Ŀγ̿�����Ϣ
    while(z==1)
    {
        newcourse_time=(COURSE_INFO_TIME *)malloc(sizeof(COURSE_INFO_TIME));
        printf("\n����ÿγ��Ͽ���������ܼ� �ڼ������ڼ��ڿ� �ڼ������ڼ��� �Ͽ�¥�� ��������");
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

        printf("\n����1����¼�룬����0ֹͣ¼��:");
        scanf("%d",&z);
    }*/

    ClearScreen();                          //����
    ShowMenu();                             //��ʾ�˵�

   //Ѱ�Ҷ�Ӧ��רҵ��Ϣ
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

    //�α��в������ÿγ̶�Ӧ��רҵ��Ϣ �����α�Ϊ�գ���û�ж�Ӧרҵ��Ϣ�������
    if(flag==0)
    {
        input_faculty->next=gp_head;
        gp_head=input_faculty;          //����רҵ�γ̱�����ͷ֮ǰ
        input_faculty->number_course=1;      //

        newcourse->next=input_faculty->next_course;
        input_faculty->next_course=newcourse;
        newcourse->class_number=0;
    }
    else            //�α������רҵ��Ϣ
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
    ClearScreen();                          //����
    ShowMenu();                             //��ʾ�˵�
    if(flag!=2)
    ShowModule(plabel_name1, 2);
    else
        ShowModule(plabel_name4,2);
    return true;
}

/**
 * ��������: MaintainCourseGraph_Delete
 * ��������: ɾ���γ���Ϣ
 * �������: �γ�����רҵ��Ϣ �༶��Ϣ �γ�����
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainCourseGraph_Delete(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵���γ���Ϣɾ��",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�γ�ɾ���ɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ÿγ̲����ڣ�",
                           "ȷ��"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_course;
    COURSE_INFO_GRAPH *p_info, *p_info_prior;
    int flag=0;
    char name2[50];
    //��Ϣ����
    printf("������Ҫɾ���Ŀγ�רҵ���ƣ�");
    scanf("%s",input_faculty.faculty);
    printf("������Ҫɾ���Ŀγ̵���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫɾ���Ŀγ̵��꼶��(����2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫɾ���Ŀγ̵Ĵ��＾:��1Ϊ��2Ϊ� ");
    scanf("%d",&(input_faculty.time));

    printf("������Ҫɾ���Ŀγ̵����ƣ�");
    scanf("%s",name2);

    ClearScreen();                          //����
    ShowMenu();                             //��ʾ�˵�
    //����רҵ��Ϣ
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
    if(flag==1)                 //���ڸÿγ̵�רҵ��Ϣ
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
 * ��������: MaintainCourseGraph_Modify
 * ��������: �޸Ŀγ���Ϣ
 * �������: �γ̵�רҵ��Ϣ �༶���� �γ�����
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainCourseGraph_Modify(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵���γ���Ϣ�޸�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�γ��޸ĳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ÿγ̲����ڣ�",
                           "ȷ��"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_course;
    COURSE_INFO_GRAPH *p_info;
    int flag=0;
    char name2[50];
    //������Ϣ
    printf("������Ҫ�޸ĵĿγ�רҵ���ƣ�");
    scanf("%s",input_faculty.faculty);
    printf("������Ҫ�޸ĵĿγ̵���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ�޸ĵĿγ̵��꼶��(����2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫ�޸ĵĿγ̵Ĵ��＾:��1Ϊ��2Ϊ� ");
    scanf("%d",&(input_faculty.time));

    printf("������Ҫ�޸ĵĿγ̵����ƣ�");
    scanf("%s",name2);
    //���Ҷ�Ӧ�α��Ӧ��רҵ
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

    if(flag==1)         //���ڸÿγ�����רҵ
    {
        for(p_info=p_course->next_course; p_info; p_info=p_info->next)
        {
            if(strcmp(p_info->course_name, name2)==0)
            {
                printf("�޸ĺ�ÿγ����ƣ�");
                scanf("%s",p_info->course_name);
                flag=2;
                ClearScreen();                          //����
                ShowMenu();
                break;

            }
        }
        if(flag==2) ShowModule(plabel_name1, 2);
        else
        {
            ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
        return true;
}

/**
 * ��������: MaintainClassGraph_Modify
 * ��������: �޸Ŀ�����Ϣ
 * �������: ���ö�Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClassGraph_Modify(void)   /*�޸Ŀ�����Ϣ*/
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵��������Ϣ�޸�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�����޸ĳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ÿ��ò����ڣ�",
                           "ȷ��"
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
    //��Ϣ����
    printf("������Ҫ�޸ĵĿ���רҵ���ƣ�");
    scanf("%s",input_faculty.faculty);
    printf("������Ҫ�޸ĵĿ��õ���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ�޸ĵĿ��õ��꼶��(����2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫ�޸ĵĿ��õĴ��＾:��1Ϊ��2Ϊ� ");
    scanf("%d",&(input_faculty.time));
    printf("������Ҫ�޸ĵĿ��õ����ƣ�");
    scanf("%s",name2);
    printf("������úϰ�����");
    scanf("%d",&(class_number));
    printf("����������༶�ţ�");
    for(i=0; i<class_number; ++i)
        scanf("%d",class_name+i);

    printf("������Ҫ�޸ĵĿ��������ڼ� �ڼ��ڵ��ڼ��� �ڼ��ܵ��ڼ��� ��");
    scanf("%d %d %d %d %d",&(day),&part1,&part2,&(week1),&week2);

    //Ѱ�Ҹÿ��õ�רҵ��Ӧ��רҵ��Ϣ
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
    //�ҵ���Ӧ��רҵ��Ϣ
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
                printf("�������޸ĺ�ÿ������ڽ�ѧ¥ ���ң�");
                scanf("%s %s",p_class->building,p_class->classroom);
                ClearScreen();                          //����
                ShowMenu();
                ShowModule(plabel_name1, 2);
            }
            else
            {
                ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
            }
        }
        else
        {
            ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
    return true;
}

/**
 * ��������: MaintainClassGraph_Add
 * ��������: ���ӿ�����Ϣ
 * �������: ���ö�Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClassGraph_Add(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵��������Ϣ����",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�������ӳɹ���",
                           "ȷ��"
                          };
    char *plabel_name3[] = {"�ÿ����Ѵ��ڣ�",
                           "ȷ��"
                          };
    char *plabel_name2[]= {"�ÿ��ö�Ӧ�γ̲����ڣ�",
                            "ȷ��"
                          };
    COURSE_GRAPH input_faculty;
    COURSE_GRAPH *p_faculty;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *input_class, *p_class, *p;

    input_class=(CLASS_INFO_GRAPH *)malloc(sizeof(CLASS_INFO_GRAPH));

    char name2[50];
    int i,z;
    int flag=0;
    //��Ϣ����
    printf("������Ҫ���ӵĿ��õ�רҵ���ƣ�");
    scanf("%s",input_faculty.faculty);
    printf("������Ҫ���ӵĿ��õ���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ���ӵĿ��õ��꼶��(����2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫ���ӵĿ��õĴ��＾:��1Ϊ��2Ϊ� ");
    scanf("%d",&(input_faculty.time));
    printf("������Ҫ���ӵĿ��õĿγ����ƣ�");
    scanf("%s",name2);

    printf("������ÿ��úϰ�����");
    scanf("%d",&(input_class->class_number));
    printf("����������༶�ţ�");
    for(i=0; i<input_class->class_number; ++i)
        scanf("%d",input_class->class_name+i);
    printf("������ÿ��ý�ʦ����");
    scanf("%d",&(input_class->teacher_number));
    printf("�������ʦ���ƣ�");
    for(i=0; i<input_class->teacher_number; ++i)
    {
        scanf("%s",input_class->teacher[i].teacher);
    }


    //Ѱ�Ҹÿ��õ�רҵ��Ӧ��רҵ��Ϣ
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
    //�ҵ���Ӧ��רҵ��Ϣ
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
            printf("������1��ʼ�������ʱ�䣬����0ֹͣ���룺");
            scanf("%d",&z);
            while(z==1)
            {
                p_class=(CLASS_INFO_GRAPH *)malloc(sizeof(CLASS_INFO_GRAPH));
                printf("�������ʱ�䣺�ܼ� �ڼ��ڵ��ڼ��� �ڼ��ܵ��ڼ��� ¥�� ���ң�");
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
                printf("������1��ʼ�������ʱ�䣬����0ֹͣ���룺");
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
            ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else
    {
        ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
    return true;
}

/**
 * ��������: MaintainClassGraph_Delete
 * ��������: ɾ��������Ϣ
 * �������: ���ö�Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClassGraph_Delete(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵��������Ϣɾ��",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"����ɾ���ɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ÿ��ò����ڣ�",
                           "ȷ��"
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
    //���ö�Ӧ����Ϣ����
    printf("������Ҫɾ���Ŀ���רҵ���ƣ�");
    scanf("%s",input_faculty.faculty);
    printf("������Ҫɾ���Ŀ��õ���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫɾ���Ŀ��õ��꼶��(����2016) ");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫɾ���Ŀ��õĴ��＾:��1Ϊ��2Ϊ� ");
    scanf("%d",&(input_faculty.time));
    printf("������úϰ�����");
    scanf("%d",&class_number);
    printf("����������༶�ţ�");
    for(i=0; i<class_number; ++i)
        scanf("%d",class_name+i);
    printf("������Ҫɾ���Ŀ��õ����ƣ�");
    scanf("%s",name2);
    printf("������Ҫɾ���Ŀ��������ڼ� �ڼ��ڵ��ڼ��� �ڼ��ܵ��ڼ��� ��");
    scanf("%d %d %d %d %d",&(input_time.day),&(input_time.course_prior),&(input_time.course_next)
          ,&(input_time.week_prior),&(input_time.week_next) );

    ClearScreen();
    ShowMenu();

    //Ѱ�Ҹÿ��õ�רҵ��Ӧ��רҵ��Ϣ
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
    //�ҵ���Ӧ��רҵ��Ϣ
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
            ClearScreen();                          //����
        ShowMenu();
        ShowModule(plabel_name2, 2);
        }
    }
    else                               //�Ŀ��ö�Ӧ��רҵ������
        ShowModule(plabel_name2, 2);

    return true;
}

/**
 * ��������: MaintainClass_Add
 * ��������: ���Ӱ༶��Ϣ
 * �������: �༶��Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClass_Add(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵���༶����",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�༶���ӳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ð༶�Ѵ��ڣ�",
                           "ȷ��"
                          };
    char *plabel_name3[] = {"�ڴ����ʧ�ܣ�",
                           "ȷ��"
                          };
    CLASS_FACULTY_INFO *newbase, *p_faculty;
    CLASS_INFO *p_class;
    CLASS_INFO *input_class;
    int flag=0;
    int i;
    char input_faculty[40];
    //�����ڴ�
    input_class=(CLASS_INFO *)malloc(sizeof(CLASS_INFO));
    input_class->next=NULL;

    //��Ϣ����
    printf("������Ҫ���ӵİ༶����רҵ�����ƣ�");
    scanf("%s",input_faculty);
    printf("������Ҫ���ӵİ༶����ţ�");
    scanf("%d",&(input_class->class_name));
    printf("������ð༶ѧ������");
    scanf("%d",&(input_class->student_number));

    ClearScreen();
    ShowMenu();

    //Ѱ�Ҷ�Ӧ��רҵ���ҵ���flag����1��������ѭ��
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(input_faculty, g_class.elem[i].faculty)==0)
        {
            flag=1;
            break;
        }
    }

    //�ҵ���Ӧ��רҵ
    if(flag==1)
    {   //������רҵ�İ༶�����Ƿ���ڸð༶������������ѭ������ʱp_class��ΪNULL
        for(p_class=g_class.elem[i].head; p_class!=NULL; p_class=p_class->next)
        {
            if(p_class->class_name==input_class->class_name)
                break;
        }
        if(p_class==NULL)               // �����ڸð༶������
        {
            input_class->next=g_class.elem[i].head;
            g_class.elem[i].head=input_class;       //������ͷ
            ++(g_class.elem[i].class_number);
            ShowModule(plabel_name1, 2);
        }
        else            //�Ѵ��ڸð༶�������ʾ��Ϣ
            ShowModule(plabel_name2, 2);
    }
    //û�ҵ���Ӧ��רҵ
    else
    {   //�ڴ�����������ڴ�
        if(g_class.length>=g_class.listlize)
        {
            newbase=(CLASS_FACULTY_INFO *)
                    realloc(g_class.elem, (g_class.listlize+LISTINCREMENT)*sizeof(CLASS_FACULTY_INFO));
            if(newbase==NULL)                   //�ڴ����ʧ��
            {
                ShowModule(plabel_name3, 2);
                return true;
            }
            g_class.elem=newbase;                               //�޸��ڴ��ַ
            g_class.listlize=g_class.listlize+LISTINCREMENT;    //�޸Ŀ����ڴ泤��
        }
        p_faculty=g_class.elem+g_class.length;
        strcpy(p_faculty->faculty, input_faculty);
        p_faculty->class_number=1;      //�༶��Ϊ1
        ++(g_class.length);             //רҵ��һ
        p_faculty->head=input_class;    //����༶���
        ShowModule(plabel_name1, 2);
    }
    return true;
}

/**
 * ��������: MaintainClass_Modify
 * ��������: �޸İ༶��Ϣ
 * �������: �༶��Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClass_Modify(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵���༶�޸�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�༶�޸ĳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ð༶�����ڣ�",
                           "ȷ��"
                          };
    CLASS_INFO *p_class;
    int flag=0;
    int i;
    int input_class;
    char input_faculty[40];
    //��Ϣ����
    printf("������Ҫ�޸ĵİ༶����רҵ��");
    scanf("%s",input_faculty);
    printf("������Ҫ�޸ĵİ༶��ţ�");
    scanf("%d",&input_class);
    //���Ҷ�Ӧ��רҵ
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(g_class.elem[i].faculty, input_faculty)==0)
        {
            flag=1;
            break;
        }
    }

    //�ҵ���Ӧ��רҵ
    if(flag==1)
    {   //������רҵ�༶���Ҹð༶,���ҵ�����ѭ������ʱp_class��ΪNULL
        for(p_class=g_class.elem[i].head; p_class!=NULL; p_class=p_class->next)
        {
            if(p_class->class_name==input_class)
                break;
        }
        //�ҵ��ð༶
        if(p_class!=NULL)
        {
            printf("�������޸ĺ�ð༶������");
            scanf("%d",&(p_class->student_number));
            ClearScreen();
            ShowMenu();
            ShowModule(plabel_name1, 2);
        }
        //û���ҵ��ð༶
        else
        {
            ClearScreen();
            ShowMenu();
            ShowModule(plabel_name2, 2);
        }
    }
    //û���ҵ���Ӧ��רҵ
    else
    {
        ClearScreen();
        ShowMenu();
        ShowModule(plabel_name2, 2);
    }
    return true;
}

/**
 * ��������: MaintainClass_Delete
 * ��������: ɾ���༶��Ϣ
 * �������: �༶��Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainClass_Delete(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵���༶ɾ��",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"�༶ɾ���ɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ð༶�����ڣ�",
                           "ȷ��"
                          };
    char input_faculty[40];
    int input_class;
    CLASS_INFO *p_class, *p_class_prior;
    int flag=0;
    int i;
    //��Ϣ����
    printf("������Ҫɾ���İ༶����רҵ��");
    scanf("%s",input_faculty);
    printf("������Ҫɾ���İ༶��ţ�");
    scanf("%d",&input_class);

    ClearScreen();
    ShowMenu();

    //���Ҷ�Ӧ��רҵ
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(g_class.elem[i].faculty, input_faculty)==0)
        {
            flag=1;
            break;
        }
    }
    //�ҵ���Ӧ��רҵ
    if(flag==1)
    {
        p_class=g_class.elem[i].head;
        //�жϵ�һ���Ƿ��Ǹð༶
        if(p_class->class_name ==input_class)
        {
            g_class.elem[i].head=p_class->next;        //�޸�����
            free(p_class);
            --(g_class.elem[i].class_number);       //��רҵ�༶����һ
            ShowModule(plabel_name1, 2);
        }
        else
        {
            p_class_prior=p_class;      //p_classǰ��
            //��������İ༶�������Ƿ���ڣ�����������ѭ������ʱp_class��ΪNULL
            for(p_class=p_class->next; p_class!=NULL; p_class=p_class->next)
            {
                if(p_class->class_name==input_class)
                    break;
                p_class_prior=p_class;
            }
            //�ҵ��ð༶
            if(p_class!=NULL)
            {
                p_class_prior->next=p_class->next;    //�޸�����
                free(p_class);
                --(g_class.elem[i].class_number);   // ��רҵ�༶����һ
                ShowModule(plabel_name1, 2);
            }
            //�ð༶������
            else
                ShowModule(plabel_name2, 2);
        }
    }
    //û���ҵ���Ӧ��רҵ
    else
        ShowModule(plabel_name2, 2);
    return true;
}

/**
 * ��������: MaintainTeacher_Add
 * ��������: ���ӽ�ʦ��Ϣ
 * �������: ��ʦ��Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainTeacher_Add(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵����ʦ����",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"��ʦ���ӳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ý�ʦ�Ѵ��ڣ�",
                           "ȷ��"
                          };
    char *plabel_name3[] = {"�ڴ����ʧ�ܣ�",
                           "ȷ��"
                          };
    TEACHER_INFO *newbase, *p_teacher;
    //�ڴ����
    newbase=(TEACHER_INFO *)malloc(sizeof(TEACHER_INFO));
    if(newbase==NULL)
    {
        ShowModule(plabel_name3, 2);
        return true;
    }
    //��ʦ��Ϣ����
    printf("������������ʦ������");
    scanf("%s",newbase->name);
    printf("������������ʦְ�ƣ�");
    scanf("%s",newbase->rank);
    ClearScreen();
    ShowMenu();
    //�������н�ʦ�����Ƿ��Ѵ���
    for(p_teacher=gp_teacher; p_teacher!=NULL; p_teacher=p_teacher->next)
    {
        if(strcmp(p_teacher->name, newbase->name)==0)
            break;
    }
    //�����ڸý�ʦ
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
 * ��������: MaintainTeacher_Delete
 * ��������: ɾ����ʦ��Ϣ
 * �������: ��ʦ��Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainTeacher_Delete(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵����ʦɾ��",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"��ʦɾ���ɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ý�ʦ�����ڣ�",
                           "ȷ��"
                          };
    TEACHER_INFO *p_teacher, *p_teacher_prior;
    char input_name[15];
    //��ʦ��Ϣ����
    printf("������Ҫɾ����ʦ�����ƣ�");
    scanf("%s",input_name);
    ClearScreen();  ShowMenu();
    p_teacher=gp_teacher;
    //����Ϊ��
    if(gp_teacher==NULL)
    {
        ShowModule(plabel_name2, 2);
        return true;
    }

    //��������е�һ����ʦ��ΪҪɾ���Ľ�ʦ
    if(strcmp(p_teacher->name, input_name)==0)
    {
        gp_teacher=p_teacher->next;
        free(p_teacher);
        ShowModule(plabel_name1, 2);
    }
    else
    {
        p_teacher_prior=p_teacher;
        //������ÿ����ʦ ���Ҹý�ʦ
        for(p_teacher=p_teacher->next; p_teacher!=NULL; p_teacher=p_teacher->next)
        {
            if(strcmp(p_teacher->name, input_name)==0)
                break;
            p_teacher_prior=p_teacher;
        }
        if(p_teacher==NULL)
            ShowModule(plabel_name2, 2);
        else    //�ҵ�ɾ���ý�ʦ
        {
            p_teacher_prior->next=p_teacher->next;
            free(p_teacher);
            ShowModule(plabel_name1, 2);
        }
    }
    return true;
}

/**
 * ��������: MaintainTeacher_Modify
 * ��������: �޸Ľ�ʦ��Ϣ
 * �������: ��ʦ��Ӧ�ľ�����Ϣ
 * �������: ��
 * �� �� ֵ: true
 */
int MaintainTeacher_Modify(void)
{
    char *plabel_name[] = {"���˵������ά��",
                           "�Ӳ˵����ʦ�޸�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char *plabel_name1[] = {"��ʦ�޸ĳɹ���",
                           "ȷ��"
                          };
    char *plabel_name2[] = {"�ý�ʦ�����ڣ�",
                           "ȷ��"
                          };
    TEACHER_INFO *p_teacher;
    char input_name[15];

    printf("������Ҫ�޸ĵĽ�ʦ���ƣ�");
    scanf("%s",input_name);
    //���Ҹý�ʦ���ҵ�����ѭ��
    for(p_teacher=gp_teacher; p_teacher!=NULL; p_teacher=p_teacher->next)
    {
        if(strcmp(p_teacher->name, input_name)==0)
            break;
    }
    if(p_teacher==NULL)
        ShowModule(plabel_name2, 2);
    else
    {
        printf("�������޸ĺ�ý�ʦ��ְ�ƣ�");
        scanf("%s",p_teacher->rank);
        ShowModule(plabel_name1, 2);
    }
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: QuerryTeacher
 * ��������: ��ѯ��ʦ��Ϣ
 * �������: ��ʦ����
 * �������: ��
 * �� �� ֵ: true
 */
int QueryTeacher(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵����ʦְ�Ʋ�ѯ",
                           "ȷ��"
                          };
    char *plabel_name1[] = {"�ý�ʦ�����ڣ�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    TEACHER_INFO *p_teacher;
    char input_name[15];

    printf("������Ҫ��ѯ�Ľ�ʦ���ƣ�");
    scanf("%s",input_name);
    //�������н�ʦ��ѯ�ý�ʦ
    for(p_teacher=gp_teacher; p_teacher!=NULL; p_teacher=p_teacher->next)
    {
        if(strcmp(p_teacher->name, input_name)==0)
        {
            printf("\n�ý�ʦְ��Ϊ��%s\n",p_teacher->rank);        //��ѯ���ý�ʦ���ְ��
            break;                                                 //������ѭ������ʱp_teacher��ΪNULL
        }
    }
    //p_teacherΪNULLʱ��˵�������ڸý�ʦ
    if(p_teacher==NULL)
        ShowModule(plabel_name1, 2);
    if(p_teacher!=NULL)
    {
        printf("\n��ѯ�ɹ��������������...");
        getchar();  getchar();
    }
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: QuerryClassroom
 * ��������: ��ѯ������Ϣ
 * �������: ��ѧ¥���������
 * �������: ��
 * �� �� ֵ: true
 */
int QueryClassroom(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵������������ѯ",
                           "ȷ��"
                          };
    char *plabel_name1[] = {"�ý��Ҳ����ڣ�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char input_building[20], input_classroom[20];
    CLASSROOM_NAME *p_classsroom;
    int i;
    int flag=0;

    printf("������Ҫ��ѯ�Ľ�������¥����");
    scanf("%s",input_building);
    printf("������Ҫ��ѯ�Ľ������ƣ�");
    scanf("%s",input_classroom);
    //��ѯ��Ӧ��¥��
    for(i=0; i<g_classroom.length; ++i)
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
        {
            flag=1;
            break;
        }
    }
    //�ҵ���Ӧ¥��
    if(flag==1)
    {
        for(p_classsroom=g_classroom.elem[i].head; p_classsroom!=NULL; p_classsroom=p_classsroom->next)
        {
            if(strcmp(p_classsroom->classroom, input_classroom)==0)
            {
                printf("\n�ý�������Ϊ��%d\n",p_classsroom->number);
                break;
            }
        }
        //������ʾ��Ϣ
        if(p_classsroom!=NULL)
        {
            printf("\n��ѯ�ɹ��������������...");
            getchar(); getchar();
        }
        else
            ShowModule(plabel_name1, 2);

    }
    //û�ҵ���Ӧ��¥��
    else
        ShowModule(plabel_name1, 2);
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: QuerryClass
 * ��������: ��ѯ�༶��Ϣ
 * �������: �༶���� רҵ����
 * �������: ��
 * �� �� ֵ: true
 */
int QueryClass(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵���༶������ѯ",
                           "ȷ��"
                          };
    char *plabel_name1[] = {"�ð༶�����ڣ�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char input_faculty[40];
    int input_class;
    CLASS_INFO *p_class;
    int i;
    int flag=0;

    printf("�������ѯ�İ༶����רҵ��");
    scanf("%s",input_faculty);
    printf("�������ѯ�İ༶����ţ�");
    scanf("%d",&input_class);
    //��������רҵ
    for(i=0; i<g_class.length; ++i)
    {
        if(strcmp(g_class.elem[i].faculty, input_faculty)==0)
        {
            flag=1;
            break;
        }
    }
    //�ҵ���Ӧ��רҵ
    if(flag==1)
    {               //������רҵ�İ༶���Ҹð༶
        for(p_class=g_class.elem[i].head; p_class!=NULL; p_class=p_class->next)
        {           //�ҵ��ð༶ʱ�����������������ѭ��
            if(p_class->class_name==input_class)
            {
                printf("\n�ð༶����Ϊ��%d\n",p_class->student_number);
                break;
            }
        }
        if(p_class!=NULL)           //�ð༶����ʱ��p_class��ΪNULL
        {
            printf("\n��ѯ�ɹ��������������...\n");
            getchar();  getchar();
        }
        else                        //�ð༶������
            ShowModule(plabel_name1, 2);
    }
    //�����ڸð༶��Ӧ��רҵ
    else
        ShowModule(plabel_name1, 2);
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: QuerryCourse
 * ��������: ��ѯ�γ���Ϣ
 * �������: �γ�����
 * �������: ��
 * �� �� ֵ: true
 */
int QueryCourse(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵���γ���Ϣ��ѯ",
                           "ȷ��"
                          };
    char *plabel_name1[] = {"�ÿγ̲����ڣ�",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    COURSE_GRAPH input_graph;
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class, *p;
    COURSE_INFO_GRAPH *p_course;
    int i;
    char input_course[50];
    int flag=0;

    printf("������Ҫ��ѯ�Ŀγ�����רҵ���ƣ�");
    scanf("%s",input_graph.faculty);
    printf("������Ҫ��ѯ�Ŀγ̵���ݣ�");
    scanf("%d",&(input_graph.year));
    printf("������Ҫ��ѯ�Ŀγ̴��＾����1Ϊ��2Ϊ�");
    scanf("%d",&(input_graph.time));
    printf("������Ҫ��ѯ�Ŀγ̵��꼶��������2016��");
    scanf("%d",&(input_graph.grade));
    printf("������ÿγ����ƣ�");
    scanf("%s",input_course);
    //���Ҷ�Ӧ��רҵ
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
    //�ҵ���רҵ
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
                        printf("%d�� ",p_class->class_name[i]);
                        printf("�ον�ʦΪ:\n");
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
                printf("\n��ѯ�ɹ��������������...");
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
 * ��������: QuerryClassGraph
 * ��������: ��ѯ������Ϣ
 * �������: ���ö�Ӧ�ľ���ʱ��
 * �������: ��
 * �� �� ֵ: true
 */
int QueryClassGraph(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵��������Ϣ��ѯ",
                           "ȷ��"
                          };
    char *plabel_name1[] = {"�ÿ��ò����ڣ�",
                           "ȷ��"
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
    //������Ϣ����
    printf("������Ҫ��ѯ�Ŀ�������רҵ��");
    scanf("%s",input_graph.faculty);
    printf("������Ҫ��ѯ�Ŀ��õ���ݣ�");
    scanf("%d",&(input_graph.year));
    printf("������Ҫ��ѯ�Ŀ��ô��＾����1Ϊ��2Ϊ�");
    scanf("%d",&(input_graph.time));
    printf("������Ҫ��ѯ�Ŀ��õ��꼶��������2016��");
    scanf("%d",&(input_graph.grade));
    printf("������úϰ�����");
    scanf("%d",&class_number);
    printf("����������༶�ţ�");
    for(i=0; i<class_number; ++i)
        scanf("%d",class_name+i);
    printf("������ÿ��õĿγ����ƣ�");
    scanf("%s",input_course);
    //printf("������Ҫ��ѯ�Ŀ��õڼ��ܵ��ڼ��ܣ��ܼ����ڼ��ڵ��ڼ��ڣ�");
    //scanf("%d %d %d %d %d",&(input_time.week_prior),&(input_time.week_next),
    //      &(input_time.day),&(input_time.course_prior),&(input_time.course_next) );
    ClearScreen();  ShowMenu();
    printf("�ÿ�����ϢΪ��\n");
    //�������Ҷ�Ӧ��רҵ���ҵ���flagΪ1��������ѭ��
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
    //�ҵ���Ӧ��רҵ
    if(flag==1)
    {   //���Ҷ�Ӧ�Ŀγ�,�ҵ���flagΪ2������ѭ��
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            if(strcmp(p_course->course_name, input_course)==0)
            {
               flag=2;
               break;
            }
        }
        //�ҵ���Ӧ�Ŀγ�
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
                    printf("\n��%2d�ܵ���%2d��    ����%2d  ��%2d�ڵ���%2d��\n",p_class->week_prior
                           ,p_class->week_next,p_class->day,p_class->course_prior,p_class->course_next);
                    printf("\n��ʦ��");
                    for(j=0;j<p_class->teacher_number; ++j)
                        printf("%s ",p_class->teacher[j].teacher);
                    printf("\n�ص㣺%s %s\n",p_class->building,p_class->classroom);
                }
            }
        }
        else
            ShowModule(plabel_name1, 2);
    }
    else
        ShowModule(plabel_name1, 2);
    printf("\n\n�����������...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * ��������: QuerryFreeClassroom
 * ��������: ��ѯ���н���
 * �������: ¥������ ����ʱ��
 * �������: ��
 * �� �� ֵ: true
 */
int QueryFreeClassroom(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵�����н��Ҳ�ѯ",
                           "ȷ��"
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

    printf("������Ҫ��ѯ���н��ҵ�¥����");
    scanf("%s",input_building);
    printf("������Ҫ��ѯ���н��ҵ���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ��ѯ���н��ҵĴ��＾��1��2���");
    scanf("%d",&(input_faculty.time));
    printf("������Ҫ��ѯ���н��ҵ�ʱ�䣺�ڼ��� �ܼ� ");
    scanf("%d %d",&week,&day);
    //���Ҷ�Ӧ�Ľ�ѧ¥
    for(i=0;i<g_classroom.length;++i)
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
            break;
    }
    if(i<g_classroom.length)    //�ҵ���ѧ¥
    {
        for(k=1; k<12; k=k+2)
        {
        classroom_number=g_classroom.elem[i].classroom_number;      // ��¥��������
        base=(int *)malloc(classroom_number*sizeof(int));           //Ϊÿ�����ҷ���һ����ַ
        for(j=0;j<classroom_number;++j)                             //��������ڴ�ȫ����ʼ��Ϊ1����ʾδʹ��
            *(base+j)=0;
        for(p_graph=gp_head; p_graph!=NULL; p_graph=p_graph->next)  //������Ӧʱ���ÿ������
        {                                                           //����ռ�õĽ���Ϊ��Ϊ 1
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
        printf("\n\n��%d %d�ڿ��н���Ϊ��\n",k,(k+1));
        for(z=0,j=0,p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
        {
            if(*(base+z)==0)                    //��ӦΪ0��ʾΪռ��
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
        printf("\n��¥�������ڣ�\n");
    printf("\n\n�����������...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * ��������: SearchCourseByTeacher
 * ��������: ����ʦ����������Ϣ
 * �������: ��ʦ����
 * �������: ��
 * �� �� ֵ: true
 */
int SearchCourseByTeacher(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵������ʦ��������",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char input_teacher[20];
    int i,flag,flag1;
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class, *p;
    COURSE_INFO_GRAPH *p_course;

    printf("������Ҫ�����Ľ�ʦ���ƣ�");
    scanf("%s",input_teacher);
    //����ÿ�����ã����Ϊ��Ӧ�Ľ�ʦ ���
    printf("\n�ý�ʦ���ο���Ϊ��\n");
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
                        printf("\n%d�� %d�� ",p_graph->year,p_graph->grade);
                        if(p_graph->time==1)    printf("����\n");
                        else    printf("�＾\n");
                        flag=1;
                    }
                    printf("\n");
                    for(i=0;i<p_class->class_number;++i)
                        printf("%d�� ",p_class->class_name[i]);
                    printf(" %s",p_course->course_name);
                    printf("\n");
                    printf("%2d�ܵ�%2d��   ����%d    ��%2d�ڵ���%2d�� %s  %s\n",p_class->week_prior,p_class->week_next
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
                        printf("%2d�ܵ�%2d��   ����%d    ��%2d�ڵ���%2d�� %s  %s\n",p->week_prior,p->week_next
                        ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                    }
                    p_class=p;
                }
                else
                    p_class=p_class->next;
            }

        }//�γ�
    }//רҵ
    printf("\n\n�����������...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: SearchCourseByClass
 * ��������: ���༶����������Ϣ
 * �������: �༶����
 * �������: ��
 * �� �� ֵ: true
 */
int SearchCourseByClass(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵�����༶��������",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    int input_class;
    char input_faculty[40];
    COURSE_GRAPH *p_graph;
    CLASS_INFO_GRAPH *p_class;
    int i, flag, grade;
    COURSE_INFO_GRAPH *p_course;

    printf("������ð༶����רҵ��");
    scanf("%s",input_faculty);
    printf("������Ҫ�����İ༶��ţ�");
    scanf("%d",&input_class);
    printf("������ð༶���꼶��");
    scanf("%d",&grade);
    printf("�ð༶����Ϊ��\n");
    //����ÿ���������Ϊ��Ӧ�İ༶ ���
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag=0;
        if(strcmp(p_graph->faculty,input_faculty)==0 &&
           p_graph->grade==grade)
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            if(flag==0)
            {
                printf("\n%d�� ",p_graph->year);
                if(p_graph->time==1)    printf("������\n");
                else    printf("�＾��\n");
            }
            printf("\n%s\n\n",p_course->course_name);
            for(p_class=p_course->next_class; p_class; p_class=p_class->next)
            for(i=0; i<p_class->class_number; ++i)
            {
                if(p_class->class_name[i]==input_class)
                {

                    printf("��%2d�ܵ���%2d�� ����%2d ��%2d�ڵ���%2d��",p_class->week_prior,p_class->week_next,
                            p_class->day,p_class->course_prior,p_class->course_next);
                    printf(" %s %s\n",p_class->building,p_class->classroom);

                    flag=1;

                }
            }
        }//�༶
    }//רҵ

    printf("\n\n�����������...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: SearchCourseByCourse
 * ��������: ���γ̼���������Ϣ
 * �������: �γ�����
 * �������: ��
 * �� �� ֵ: true
 */
int SearchCourseByCourse(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵�����γ̼�������",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char input_course[50];
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class, *p;
    int i,flag;
    printf("������Ҫ�����Ŀγ����ƣ�");
    scanf("%s",input_course);
    //printf("������ÿγ̵�רҵȫ�ƣ�");
    //scanf("%s",input_faculty);
    printf("\n�ÿγ̿���Ϊ��\n");
    //����ÿ���γ̣��ҵ��ÿγ� �������
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
                        printf("\n%d�� ",p_graph->year);
                        if(p_graph->time==1)    printf("������\n");
                        else    printf("�＾��\n");
                        printf(" %s",p_graph->faculty);
                        flag=1;
                    }
                    printf("\n");
                    for(i=0; i<p_class->class_number; ++i)
                    {
                        printf("%d��",p_class->class_name[i]);
                    }
                    printf("\n");

                        printf("��%2d�ܵ���%2d�� ����%2d ��%2d�ڵ���%2d��",p_class->week_prior,p_class->week_next
                               ,p_class->day,p_class->course_prior,p_class->course_next);
                        printf(" %s %s\n",p_class->building,p_class->classroom);

                }*/
                for(p_class=p_course->next_class; p_class;  )
            {
                if(flag==0)
                    {
                        printf("\n%d�� ",p_graph->year);
                        if(p_graph->time==1)    printf("������\n");
                        else    printf("�＾��\n");
                        printf(" %s",p_graph->faculty);
                        flag=1;
                    }
                printf("\n");
                for(i=0;i<p_class->class_number;++i)
                    printf("%d�� ",p_class->class_name[i]);
                for(i=0; i<p_class->teacher_number; ++i)
                    printf(" %s",p_class->teacher[i].teacher);
                printf("\n");
                printf("%2d�ܵ�%2d��   ����%d    ��%2d�ڵ���%2d�� %s  %s\n",p_class->week_prior,p_class->week_next
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
                    printf("%2d�ܵ�%2d��   ����%d    ��%2d�ڵ���%2d�� %s  %s\n",p->week_prior,p->week_next
                    ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                }
                p_class=p;
            }
            }
        }//�γ�

    }//רҵ
    printf("\n\n�����������...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: SearchCourseByClassroom
 * ��������: �����Ҽ���������Ϣ
 * �������: ��������
 * �������: ��
 * �� �� ֵ: true
 */
int SearchCourseByClassroom(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵�������Ҽ�������",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    char input_classroom[20], input_building[20];
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    CLASS_INFO_GRAPH *p_class, *p;
    int i,flag, flag1;
    printf("������Ҫ�����Ľ�������¥����");
    scanf("%s",input_building);
    printf("������Ҫ�����Ľ������ƣ�");
    scanf("%s",input_classroom);
    printf("\n�ý��ҿ���Ϊ��\n");
    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag1=0;

            for(p_course=p_graph->next_course,flag=0; p_course; p_course=p_course->next,flag=0)
            {
               for(p_class=p_course->next_class; p_class; )
               {    //�����������Ҫ�� �����Ϣ
                   if(strcmp(p_class->building,input_building)==0&&
                      strcmp(p_class->classroom,input_classroom)==0)
                    {
                        if(flag1==0)
                        {       //flag1���ڿ��� רҵ �꼶�����
                            printf("\n%d�� %d�� ",p_graph->year,p_graph->grade);
                            printf(" %s ",p_graph->faculty);
                            if(p_graph->time==1)    printf("������\n");
                            else    printf("�＾��\n");
                            flag1=1;
                        }
                        if(flag==0)     //flag���ڿ��ƿγ��������
                        {
                            printf("\n%s\n\n",p_course->course_name);
                        }
                        for(i=0; i<p_class->class_number; ++i)
                                printf("%d��",p_class->class_name[i]);
                        printf("\n");
                        printf("%2d�ܵ�%2d��   ����%2d   ��%2d�ڵ���%2d��",p_class->week_prior,p_class->week_next
                               ,p_class->day,p_class->course_prior,p_class->course_next);
                        printf(" %s %s\n",p_class->building,p_class->classroom);
                        flag=1;
                        for(p=p_class->next; p; p=p->next)
                        {           //��ѭ������������иð༶�ÿγ̵Ŀ������ ��ֻ���һ�κϰ�
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
                            printf("%2d�ܵ�%2d��   ����%2d   ��%2d�ڵ���%2d�� %s %s\n",p->week_prior,p->week_next
                            ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                        }
                        p_class=p;
                    }
                    else
                        p_class=p_class->next;
               }
            }

    }
    printf("\n\n�����������...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: SearchCourseByTime
 * ��������: ��ʱ�����������Ϣ
 * �������: �������ʱ��
 * �������: ��
 * �� �� ֵ: true
 */
int SearchCourseByTime(void)
{
    char *plabel_name[] = {"���˵�����ݲ�ѯ",
                           "�Ӳ˵����ʱ���������",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    COURSE_GRAPH *p_graph;
    COURSE_INFO_GRAPH *p_course;
    COURSE_GRAPH input_faculty;
    CLASS_INFO_GRAPH *p_class, input_time;
    int i,j,flag;
    int week;
    printf("������Ҫ�������õ�ʱ����ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ�������õ�ʱ�䴺�＾��");
    scanf("%d",&(input_faculty.time));
    printf("������Ҫ�������õ�ʱ����ܴΣ�");
    scanf("%d",&(week));
    printf("������Ҫ�������õ�ʱ���ܼ���");
    scanf("%d",&(input_time.day));
    printf("������Ҫ�������õ�ʱ��ڼ��ڵ��ڼ��ڣ�");
    scanf("%d %d",&(input_time.course_prior), &(input_time.course_next));

    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        flag=0;
        if(p_graph->year==input_faculty.year &&
           p_graph->time==input_faculty.time )

            for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
            {
                for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                {       //�������������� ������ÿ�����Ϣ
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
                                printf("\n%s %d��\n",p_graph->faculty,p_graph->grade);
                            for(i=0;i<p_class->class_number;++i)
                                printf("%d��",p_class->class_name[i]);
                            printf(" %s %s %s\n"
                                   ,p_course->course_name,p_class->building,p_class->classroom);
                            flag=1;
                        }
                    }
                }
            }//�γ�

    }//רҵ
    printf("\n\n�����������...");
    getchar();  getchar();
    ClearScreen();
    ShowMenu();
    return true;
}

/**
 * ��������: AnalysisUsingRate
 * ��������: ���������ʷ���
 * �������: ��ѧ¥���� ����ʱ��
 * �������: ��
 * �� �� ֵ: true
 */
int AnalysisUsingRate(void)
{
    char *plabel_name[] = {"���˵�����ݷ���",
                           "�Ӳ˵�����������ʷ���",
                           "ȷ��"
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

    printf("������Ҫ�������������ʵ�¥����");
    scanf("%s",input_building);
    printf("������Ҫ�������������ʵ���ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ�������������ʵĴ��＾��1Ϊ��2Ϊ�:");
    scanf("%d",&(input_faculty.time));
    printf("������Ҫ�������������ʵ�ʱ�䣺�ڼ��� �ܼ� �ڼ��ڵ��ڼ��ڿΣ�");
    scanf("%d %d %d %d",&(week),&(input_time.day),&(input_time.course_prior),&(input_time.course_next));

    for(i=0;i<g_classroom.length;++i)
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
            break;
    }
    if(i<g_classroom.length)
    {
        classroom_number=g_classroom.elem[i].classroom_number;      // ��¥��������
        base=(int *)malloc(classroom_number*sizeof(int));           //ÿ������һ��λ�ã�1����ʹ��
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
                        j=0;        //�жϸÿ����Ƿ� ����Ҫ��
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
                        }           //�ÿ������㽫��Ӧ���Ҽ�¼
                        if(j==week)
                        {
                            for(a=0,p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
                            {
                                if(strcmp(p_classroom->classroom, p_class->classroom)==0)
                                    *(base+a)=1;            //��ý��Ҷ�Ӧ��λ�ñ��Ϊ1��ʾ��ʹ��
                                ++a;
                            }
                        }
                    }
                }

        }
        //������ǵ�ַ������ʹ�õĽ�����
        for(number=0,a=0;a<classroom_number;++a)
        {
            if(*(base+a)==1)
                ++number;
        }
        rate=(float)number/(float)classroom_number;
        printf("\n���н���%d  ʹ��%d\n",classroom_number,number);
        printf("\n�ý�ѧ¥�ڸ�ʱ�ν���������Ϊ��%f",rate);
    }
    else
        printf("\n��¥�������ڣ�\n");
    printf("\n\n�����������...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * ��������: AnalysisCourseByTeacher
 * ��������: ��ʦ�е����ú����Է���
 * �������: ��ʦ����
 * �������: ��
 * �� �� ֵ: true
 */
int AnalysisCourseByTeacher(void)
{
    char *plabel_name[] = {"���˵�����ݷ���",
                           "�Ӳ˵����ʦ�е����ú����Է���",
                           "ȷ��"
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
    for(i=0;i<1700;++i)         //��ʾһ��ѧ�ڵ����п���ʱ��
        class_time[i]=0;
    printf("������Ҫ�����е����ú����ԵĽ�ʦ���ƣ�");
    scanf("%s",input_teacher);
    printf("������Ҫ�����Ŀ�����ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ�����Ŀ����꼶��");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫ�����Ŀ��õĴ��＾��1Ϊ��2Ϊ���");
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
                                //���ý�ʦ�Ŀ���ÿ��ʱ��д��ʱ������
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
        printf("\n�ý�ʦ�ڸ�ѧ�ڸ��꼶�Ŀ��óе�����");
    else
    {               //�жϲ������ʱ���Ƿ�ʱ��ͬ�ϰ���ͬһ�ص��Ͽ�
        for(k=0; k<1700; ++k)
        {
            flag1=0;
            if(class_time[k]>1)
            for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
            {
            if(p_graph->year==input_faculty.year &&
            p_graph->grade==input_faculty.grade &&
            p_graph->time==input_faculty.time)
                    //��רҵ�α�����Ҫ��
            for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
            {
                for(p_class=p_course->next_class; p_class; p_class=p_class->next)
                for(i=0; i<p_class->teacher_number; ++i)
                if(strcmp(p_class->teacher[i].teacher, input_teacher)==0)
                {           //����ҵ��ý�ʦ

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
                                {   //����ǲ�ͬ�ϰ� ͬһ�ص� ��ʱ�������Ӧ��һ
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

    printf("\n�ý�ʦ�ڸ�ѧ�ڸ��꼶�Ŀ��óе�������ʱ�䲻����\n");
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
                printf("��%d�� ����%d ��%d��\n",week,day,part);
            }
        }
    }
    printf("\n\n�����������...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * ��������: AnalysisCourseByClass
 * ��������: �༶������ú����Է���
 * �������: �༶����
 * �������: ��
 * �� �� ֵ: true
 */
int AnalysisCourseByClass(void)
{
    char *plabel_name[] = {"���˵�����ݷ���",
                           "�Ӳ˵���༶������ú����Է���",
                           "ȷ��"
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
    for(i=0;i<1700;++i)     //���ڴ��ÿ��ʱ���Ͽ����
        class_time[i]=0;
    printf("������Ҫ�����İ༶��רҵ��");
    scanf("%s",input_faculty.faculty);
    printf("������Ҫ����������ú����Եİ༶��ţ�");
    scanf("%d",&input_class);
    printf("������Ҫ�����Ŀ�����ݣ�");
    scanf("%d",&(input_faculty.year));
    printf("������Ҫ�����Ŀ����꼶��");
    scanf("%d",&(input_faculty.grade));
    printf("������Ҫ�����Ŀ��õĴ��＾��1Ϊ��2Ϊ���");
    scanf("%d",&(input_faculty.time));

    for(p_graph=gp_head; p_graph; p_graph=p_graph->next)
    {
        if(p_graph->year==input_faculty.year &&
           p_graph->grade==input_faculty.grade &&
           p_graph->time==input_faculty.time &&
           strcmp(p_graph->faculty, input_faculty.faculty)==0)
            //����רҵ�α�Ҫ��
        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            for(p_class=p_course->next_class; p_class; p_class=p_class->next)
            {
                for(i=0; i<p_class->class_number; ++i)
                if(p_class->class_name[i]==input_class)     //�����Ҫ�����İ༶��������ʱ��¼������
                for(j=p_class->week_prior; j<=p_class->week_next;++j)
                {
                        count=(j-1)*84+(p_class->day-1)*12+p_class->course_prior;
                        ++class_time[count];
                        if(class_time[count]>1)    flag=1;      //flagΪ1��ʾ���ڲ�����
                        ++count;
                        ++class_time[count];
                        if(class_time[count]>1)    flag=1;
                }
            }
        }

    }
    if(flag==0)
        printf("\n�ð༶�ڸ�ѧ�ڵĿ��ò������");
    else
    {
        printf("\n�ð༶�ڸ�ѧ�ڵĿ��ò���������ʱ�䲻����\n");
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
                printf("��%d�� ����%d ��%d��\n",week,day,part);
            }
        }
    }
    printf("\n\n�����������...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

/**
 * ��������: AnalysisEnergy
 * ��������: ��Ч����
 * �������: �������� ����ʱ��
 * �������: ��
 * �� �� ֵ: true
 */
int AnalysisEnergy(void)
{
    char *plabel_name[] = {"���˵�����ݷ���",
                           "�Ӳ˵����Ч����",
                           "ȷ��"
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

    printf("�����������Ч�����Ľ���¥�����ƣ�");
    scanf("%s",input_building);
    printf("�����������Ч�����Ľ��ң�");
    scanf("%s",input_classroom);
    printf("�����������Ч������ʱ�䣺\n���  ���＾��1Ϊ��2Ϊ�  �ܴ�  ���ڼ�  �ڼ��ڿε��ڼ��ڿΣ�\n");
    scanf("%d %d %d %d %d %d",&(input_faculty.year),&(input_faculty.time),
          &(week),&(input_time.day),&(input_time.course_prior),&(input_time.course_next));
    classroom_capacity=0;
    number=0;
    for(i=0; i<g_classroom.length; ++i)         //����������Ϣ�����Ҹý���
    {
        if(strcmp(g_classroom.elem[i].classroom_building, input_building)==0)
        {
            for(p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
            if(strcmp(p_classroom->classroom, input_classroom)==0)
            {
                classroom_capacity=p_classroom->number;     //��������
                break;
            }
        }
    }

    if(classroom_capacity==0)
        printf("\n�ý��Ҳ����ڣ�\n");
    else
    {                             //רҵѭ��
        for(p_faculty=gp_head; p_faculty; p_faculty=p_faculty->next)
        if(p_faculty->year==input_faculty.year &&
           p_faculty->time==input_faculty.time)//�Ǹ�רҵ�α�ʱ
        {               //�γ�ѭ��
                for(p_course=p_faculty->next_course; p_course; p_course=p_course->next)
                    for(p_class=p_course->next_class; p_class; p_class=p_class->next)   //����ѭ��
                    {
                        z=0;
                        if(p_class->course_next==input_time.course_next &&
                           p_class->day==input_time.day &&
                           p_class->course_prior==input_time.course_prior &&
                           strcmp(p_class->building, input_building)==0 &&
                           strcmp(p_class->classroom, input_classroom)==0)
                        {               //�жϸÿ����Ƿ�����
                            for(z=p_class->week_prior; z<p_class->week_next; ++z)
                            {
                                if(z==week)
                                    break;
                            }
                        }
                        if(z==week)         //��������Ҫ��  ���ڸÿ��õ����а༶�������
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
        printf("\n�ý��ҹ�%dλ�ã�ʹ��%d��\n",classroom_capacity,number);
        printf("\n�ý���ʹ����Ϊ��%f\n",(float)number/(float)classroom_capacity);
    }
    printf("\n\n�����������...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * ��������: TraversalGraph
 * ��������: �����α�
 * �������: ��
 * �������: �α���Ϣ
 * �� �� ֵ: true
 */
int TraversalGraph(void)
{
    char *plabel_name[] = {"���˵����������",
                           "�Ӳ˵���α����",
                           "ȷ��"
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
        if(p_graph->time==1)    printf("���� ");
        else    printf("�＾ ");
        printf("%s %d��\n",p_graph->faculty,p_graph->grade);


        for(p_course=p_graph->next_course; p_course; p_course=p_course->next)
        {
            printf("\n%s \n",p_course->course_name);

            for(p_class=p_course->next_class; p_class;  )
            {
                printf("\n");
                //++number;
                for(i=0;i<p_class->class_number;++i)
                    printf("%d�� ",p_class->class_name[i]);      //  ����ϰ����
                for(i=0; i<p_class->teacher_number; ++i)
                    printf(" %s",p_class->teacher[i].teacher);      //��ʦ���
                printf("\n");                                   //����ʱ��
                printf("%2d�ܵ�%2d��   ����%d    ��%2d�ڵ���%2d�� %s  %s\n",p_class->week_prior,p_class->week_next
                    ,p_class->day,p_class->course_prior,p_class->course_next,p_class->building,p_class->classroom);
                for(p=p_class->next; p; p=p->next)          //��ѭ������������иð༶�ÿγ��µĿ���
                {
                    i=0;
                    if(p->class_number==p_class->class_number)
                    {                       //�ж��Ƿ��Ǹÿ���
                        for(i=0; i<p_class->class_number; ++i)
                        {
                            if(p_class->class_name[i]!=p->class_name[i])
                                break;
                        }
                    }
                    if(i!=p_class->class_number) break;
                    printf("%2d�ܵ�%2d��   ����%d    ��%2d�ڵ���%2d�� %s  %s\n",p->week_prior,p->week_next
                    ,p->day,p->course_prior,p->course_next,p->building,p->classroom);

                }
                p_class=p;
            }
        }


    }
    //printf("\n������Ϊ��%d\n",number);
    printf("\n\n���س�����...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * ��������: TraversalClass
 * ��������: �����༶
 * �������: ��
 * �������: �༶��Ϣ
 * �� �� ֵ: true
 */
int TraversalClass(void)
{
    char *plabel_name[] = {"���˵����������",
                           "�Ӳ˵���༶����",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    CLASS_INFO *p_class;
    int i;

    for(i=0; i<g_class.length; ++i)         //רҵ����
    {
        printf("\n%s\n\n",g_class.elem[i].faculty);
        //רҵ�༶����
        for(p_class=g_class.elem[i].head; p_class; p_class=p_class->next)
        {
            printf("%d�� %d��\n",p_class->class_name,p_class->student_number);
        }
    }
    printf("\n\n���س�����...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * ��������: TraversalClassroom
 * ��������: ��������
 * �������: ��
 * �������: ������Ϣ
 * �� �� ֵ: true
 */
int TraversalClassroom(void)
{
    char *plabel_name[] = {"���˵����������",
                           "�Ӳ˵�����ұ���",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    int i;
    CLASSROOM_NAME *p_classroom;
    for(i=0; i<g_classroom.length; ++i)         //������ѧ¥
    {
        printf("\n%s\n\n",g_classroom.elem[i].classroom_building);
        //������ѧ¥�����н���
        for(p_classroom=g_classroom.elem[i].head; p_classroom; p_classroom=p_classroom->next)
        {
            printf("%s  ������%d\n",p_classroom->classroom,p_classroom->number);
        }
    }
    printf("\n\n���س�����...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}
/**
 * ��������: TraversalTeacher
 * ��������: ������ʦ
 * �������: ��
 * �������: ��ʦ��Ϣ
 * �� �� ֵ: true
 */
int TraversalTeacher(void)
{
    char *plabel_name[] = {"���˵����������",
                           "�Ӳ˵����ʦ����",
                           "ȷ��"
                          };
    ShowModule(plabel_name, 3);
    TEACHER_INFO *p_teacher;
    //ѭ������ �����ʦ��Ϣ
    for(p_teacher=gp_teacher; p_teacher; p_teacher=p_teacher->next)
    {
        printf("%-10s %-10s\n",p_teacher->name,p_teacher->rank);
    }
    printf("\n\n���س�����...");
    getchar(); getchar();
    ClearScreen();  ShowMenu();
    return true;
}

