#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
  if(!fork()) //создается два идентичных потока child (!fork) и parrent (fork)
  {
    printf("ppid: %d  pid: %d\n", getppid(), getpid()); //getppid - id родителя, getpid - id потомка
    if(!fork())
    {
      printf("ppid: %d  pid: %d\n", getppid(), getpid());
      if(!fork())
      {
        printf("ppid: %d  pid: %d\n", getppid(), getpid());
        exit(0);
      }
      wait(NULL); //приостанавливает выполнение текущего процесса до тех пор, пока дочерний процесс не завершится
      exit(0);
    }
    wait(NULL);
    exit(0);
  }
  
  if(!fork())
  {
    printf("ppid: %d  pid: %d\n", getppid(), getpid());

    if(!fork())
    {
      printf("ppid: %d  pid: %d\n", getppid(), getpid());
      exit(0);
    }

    if(!fork())
    {
      printf("ppid: %d  pid: %d\n", getppid(), getpid());
      exit(0);
    }
    wait(NULL);
    wait(NULL);
    exit(0);
  }
  wait(NULL);
  wait(NULL);

  return 0;
}
