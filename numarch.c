#include <stdio.h>
#include <unistd.h>


int main() {
    int fd[2];
    pipe(fd);
    int pid = fork(); 
    if(pid==0){
        //close(0);
        dup2(1,fd[1]);
        execlp("wc","wc","-1",NULL);
    } else {
        //close(1);
        dup2(0,fd[0]);
        execlp("ls","ls",NULL);
    }
    return 0;
}