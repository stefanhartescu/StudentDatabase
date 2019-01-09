#include <stdio.h>
#include <stdlib.h>
struct student //these are the nodes of the linked list
{
    char name[40];
    int student_number;
    int n;//these are the fields within the struct (data of a student)
    float marks[60];
    struct student *next_student;
};

int main()
{
    int k=0,i=0,j=1,p=1,h;
    struct student *root;
    root=NULL;//the list is empty at the beginning
    printf("1)Introduce new student\n2)Remove student\n3)Print report of student\n4)Print report of all students\n5)Save to file\n6)Retrieve data from file\n7)Exit\n");//the menu
    while(k<7)
    {
        scanf("%d",&k);
        if(k==1)//introduce new student
        {
            struct student *last;
            struct student *new_student=(struct student*)malloc(sizeof(struct student));//this allocates memory for one student
            if(root==NULL)//the programs enters this if the list is empty
            {
                root=new_student;//here we start creating the first node (the root)
                printf("Name:");
                scanf("%s",root->name);
                printf("Student Number:");
                scanf("%d",&root->student_number);
                printf("The number of courses is:");
                scanf("%d",&root->n);
                root->next_student=NULL;
                for(i=1;i<=root->n;i++)//we add the grades for each course
                {
                    printf("Grade for course number %d:",i);
                    scanf("%f",&root->marks[i]);
                }
            }
            else//if a root already exists, the program enters this part
            {
                last=root;
                while(last!=NULL)
                {
                    if(last->next_student==NULL)//if the last student has been reached
                    {
                        last->next_student=new_student;
                        printf("Name:");
                        scanf("%s",new_student->name);
                        printf("Student Number:");//here we enter the student data for the last node
                        scanf("%d",&new_student->student_number);
                        printf("The number of courses is:");
                        scanf("%d",&new_student->n);
                        for(i=1;i<=new_student->n;i++)//grades for the courses
                        {
                            printf("Grade for course number %d:",i);
                            scanf("%f",&new_student->marks[i]);
                        }
                        new_student->next_student=NULL;//this is the last element of the list, so there is no next student
                        last=new_student->next_student;
                    }
                    else
                    {
                        last=last->next_student;//if the last student has not been reached yet, the program continues to search for it
                    }
                }
            }
        }
        if(k==2)//remove student
        {
            char name[40];//we declare a char that is used to search by name
            struct student *new_student,*current,*temp;
            if(root==NULL)//if there are no students stored yet, the program says this
            {
                printf("There are no students \n");
            }
            else
            {
                j=1;
                printf("The students are: \n");//the program starts displaying the students
                new_student=root;//it starts from the first node of the list
                while(new_student!=NULL)
                {
                    printf("%d)%s \n",j,new_student->name);
                    new_student=new_student->next_student;//it goes on to the next one
                    j++;
                }
                printf("Enter the name of the student you want to delete: ");
                scanf("%s",name);
                if((strcmp(root->name,name)!=0)&&(root->next_student==NULL))//this searches the list of students by name
                {
                    printf("The student doesn't exist \n");
                }
                else
                {
                    if(strcmp(root->name,name)==0)//if the string entered is found within the list
                    {
                        temp=root;
                        root=root->next_student;
                        free(temp);//the respective student is deleted
                    }
                    else
                    {
                        h=0;
                        temp=root;//tracking the temp node
                        current=root->next_student;
                        if((strcmp(current->name,name)==0)&&(current->next_student==NULL))
                        {
                            free(current);
                            temp->next_student=NULL;
                        }
                        else
                        {
                            while(temp->next_student!=NULL)
                            {
                                if(current->next_student==NULL)
                                {
                                    if(strcmp(current->name,name)==0)
                                    {
                                        h=1;
                                        new_student=current;
                                        free(current);
                                        temp->next_student=new_student->next_student;
                                        }
                                        else
                                        {
                                            temp=temp->next_student;
                                            current=current->next_student;
                                        }
                                }
                                else
                                {
                                    if(strcmp(current->name,name)==0)
                                    {
                                        h=1;
                                        temp->next_student=current->next_student;
                                        free(current);
                                    }
                                    else
                                    {
                                        temp=temp->next_student;
                                        current=current->next_student;
                                    }
                                }

                            }
                            if(h==0)
                            {
                                printf("The student doesn't exist \n");
                            }
                        }
                    }
                }
            }
        }
        if(k==3)//print report of a single student
        {
            char name[40];
            struct student *new_student,*current,*temp;
            if(root==NULL)//if there are no students stored yet
            {
                printf("There are no students \n");
            }
            else
            {
                j=1;
                printf("The students are: \n");
                new_student=root;//starts from the first node
                while(new_student!=NULL)//as long as there are students left in the list
                {
                    printf("%d)%s \n",j,new_student->name);
                    new_student=new_student->next_student;
                    j++;//prints the names of every student
                }
                printf("Enter the name of the student for which you want to print the report: ");
                scanf("%s",name);
                if((strcmp(root->name,name)!=0)&&(root->next_student==NULL))
                {
                    printf("The student doesn't exist \n");//if the student name entered is not found in the list
                }
                else
                {
                    if(strcmp(root->name,name)==0)//if the student is found in the list
                    {
                        printf(" Name:%s \n Student number:%d \n",root->name,root->student_number);
                        for(i=1;i<=root->n;i++)
                        {
                            printf("The mark for course %d is:%f \n",i,root->marks[i]);
                        }
                    }//this prints the data of the student
                    else
                    {
                        temp=root;//the previous element than the one that is used
                        current=root->next_student;
                        if((strcmp(current->name,name)==0)&&(current->next_student==NULL))
                        {
                            printf(" Name:%s \n Student number:%d \n",current->name,current->student_number);
                            for(i=1;i<=current->n;i++)
                            {
                                printf("The mark for course %d is:%f \n",i,current->marks[i]);
                            }
                        }
                        else
                        {
                            h=0;
                            while(temp->next_student!=NULL)//this designates the last element
                            {
                                if(current->next_student==NULL)//if the end of the list has been reached
                                {
                                    if(strcmp(current->name,name)==0)
                                    {
                                        h=1;
                                        printf(" Name:%s \n Student number:%d \n",current->name,current->student_number);
                                        for(i=1;i<=current->n;i++)
                                        {
                                            printf("The mark for course %d is:%f \n",i,current->marks[i]);
                                        }
                                        temp=temp->next_student;
                                        current=current->next_student;
                                    }
                                    else
                                    {
                                        temp=temp->next_student;//the program advances within the list
                                        current=current->next_student;
                                    }
                                }
                                else
                                {
                                if(strcmp(current->name,name)==0)//if the two names match
                                    {
                                        h=1;
                                        printf(" Name:%s \n Student number:%d \n",current->name,current->student_number);
                                        for(i=1;i<=current->n;i++)
                                        {
                                            printf("The mark for course %d is:%f \n",i,current->marks[i]);
                                        }
                                        temp=temp->next_student;
                                        current=current->next_student;
                                    }
                                    else
                                    {
                                        temp=temp->next_student;//the program advances within the list
                                        current=current->next_student;
                                    }
                                }
                            }
                            if(h==0)
                            {
                                printf("The student doesn't exist \n");
                            }
                        }
                    }
                }
            }
        }
        if(k==4)//print report of all students
        {
            struct student *new_student;
            if(root==NULL)//if there are no students in the list yet
            {
                printf("There are no students recorded\n");
            }
            else
            {
                new_student=root;
                while(new_student!=NULL)//if there are students in the list
                {
                    printf(" Name:%s \n Student number:%d \n",new_student->name,new_student->student_number);
                    for(i=1;i<=new_student->n;i++)//student marks for each course
                    {
                        printf("The mark for course %d is:%f \n",i,new_student->marks[i]);
                    }
                    new_student=new_student->next_student;//prints the data of the student and advances to the next one
                }
            }
        }
        if(k==5)//saving student data to a file
        {
            struct student *new_student;
            if(root==NULL)//if there are no students saved
            {
                printf("There are no students \n");
            }
            else
            {
                new_student=root;
                FILE *fp;//declaring the file
                fp=fopen("students.txt","w");//determines the file used
                while(new_student!=NULL)
                {
                    fprintf(fp,"Name:%s \n Student number:%d \n Number of courses:%d \n",new_student->name,new_student->student_number,new_student->n);//tjis prints all the data within the file
                    for(i=1;i<=new_student->n;i++)
                    {
                        fprintf(fp," The marks for course %d is:%f \n",i,new_student->marks[i]);//printing the marks within the file
                    }
                    new_student=new_student->next_student;
                }
                fclose(fp);//closes the file
            }
        }
        if(k==6)
        {
            char str[1000];
            FILE *fopen(),*fp;
            fp=fopen("students.txt","r");//opens the file
            if (fp == NULL) //we verify if the file is empty
            {
                printf("Could not open file \n");
            }
            else
            {
                printf("The data within the file that has been retrieved is:\n");
                while (fgets(str, 1000, fp) != NULL) //we check for every character to be different to NULL and we print them
                printf("%s", str);
                fclose(fp);
            }
        }
        if(k==7)//exits the program
        {
            return 0;
        }
        printf("\n1)Introduce new student\n2)Remove student\n3)Print report of student\n4)Print report of all students\n5)Save to file\n6)Retrieve data from file\n7)Exit\n");//the menu appears again if the exit option is not selected
    }
    return 0;
}
