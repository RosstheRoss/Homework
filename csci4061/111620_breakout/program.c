
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MATSIZE 5000

int mat1[MATSIZE][MATSIZE];
int mat2[MATSIZE][MATSIZE];


typedef struct argstruct {
    int x_start;
    int x_end;
    int y_start;
    int y_end;
    int** res_mat;
} args_t;

int getX_start(int i) {
    return (i % 2) * MATSIZE / 2;
}
int getY_start(int i) {
    return ((i < 2) ? 0 : 1) * MATSIZE / 2;
}


//TODO: Complete this function (to be accessed by a thread) which will
//      perform matrix addition on a portion of a matrix, dictated by
//      the input parameter 'args'
void * partial_matrix_add(void * args) {
    int **dest;
    args_t *input = (struct argstruct *) args;  // params can be accessed using input pointer
    dest = input->res_mat;   //can be accessed as dest[][] now

    // Todo: Your code goes here (for reference checkout the pseudo code in the slides)
    for (int i=input->x_start; i<input->x_end; i++) {
        for (int j=input->y_start; j<input->y_end; j++) {
            dest[i][j] = mat1[i][j]*mat2[i][j];
        }
    }
    return NULL;
}

int main() {
    // to store mulitple dispatcher threads
    pthread_t m_threads[4];

    // to store single default thread
    pthread_t s_thread;

    // variable to pass values to multiple thread multiplication
    args_t m_args[4];

    //variable to pass values to single thread muliplication
    args_t s_args;

    /**
     *  initializing matrices for sinlge and multiple matrix multiplication
     */
    int i, j, k, c;
    struct timeval t_multi_start, t_multi_end, t_single_start, t_single_end;
    int ** res_mat_multi = malloc(MATSIZE * sizeof(int *));
    int ** res_mat_single = malloc(MATSIZE * sizeof(int *));
    for(i = 0; i < MATSIZE; i++) {
        res_mat_multi[i] = malloc(MATSIZE * sizeof(int));
        res_mat_single[i] = malloc(MATSIZE * sizeof(int));
    }

    //Populate base matrices with random integers
    //Initialize result matrices with -1
    for(j = 0; j < MATSIZE; j++) {
        for(k = 0; k < MATSIZE; k++) {
            mat1[j][k] = rand() % 1000 + 1;
            mat2[j][k] = rand() % 1000 + 1;
            res_mat_multi[j][k] = -1;
            res_mat_single[j][k] = -1;
        }
    }
//Version 1 **************************************************************************
    //Measure time for multiple thread addition
    gettimeofday(&t_multi_start, NULL);

    //Todo: create attribute for detached threads
    //Create mulitple threads to populate res_mat_multi with the result
    //      of performing matrix addition mat1 + mat2
    for(i = 0; i < 4; i++) {

        int x_start = getX_start(i);
        int y_start = getY_start(i);
        int x_end = x_start + MATSIZE/2;
        int y_end = y_start + MATSIZE/2;
        m_args[i].res_mat = res_mat_multi;
        //your code goes here
        //Todo:Create m_agrs using  x_start, x_end, y_start, y_end, and create detached threads
        m_args[i].x_start = x_start;
        m_args[i].x_end = x_end;
        m_args[i].y_start = y_start;
        m_args[i].y_end = y_end;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
        pthread_create(&m_threads[i], &attr, partial_matrix_add, (void *) &m_args[i]);
    }

    gettimeofday(&t_multi_end, NULL);
//Version 2  *************************************************************************

    //Measure time for single thread addition
    gettimeofday(&t_single_start, NULL);

    // Create single thread to populate res_mat_multi with the result
    //      of performing matrix addition mat1 + mat2

    int x_start = 0;
    int x_end = MATSIZE;
    int y_start = 0;
    int y_end = MATSIZE;
    s_args.res_mat = res_mat_single;
    //your code goes here
    //Todo: Assign values to s_args using x_start, y_start etc.
    s_args.x_start = x_start;
    s_args.y_start = y_start;
    s_args.x_end = x_end;
    s_args.y_end = y_end;
    //Todo:Create thread
    pthread_create(&s_thread, NULL, partial_matrix_add, (void *) &s_args);
    //Todo:join thread
    pthread_join(s_thread, NULL);
    gettimeofday(&t_single_end, NULL);

// **********************************************************************************
    //Don't change anything from here
    //Test to ensure that both methods produce the same result
    c = 0;
    for(j = 0; j < MATSIZE; j++) {
        for(k = 0; k < MATSIZE; k++) {
            if(res_mat_multi[j][k] == res_mat_single[j][k] && res_mat_multi[j][k] != -1) {
                c++;
            }
        }
    }
    printf("Verification: %d out of %d entries matched.\n", c, MATSIZE * MATSIZE);
    //Display time for each version
    double time_taken;
    time_taken = (t_multi_end.tv_sec - t_multi_start.tv_sec) * 1e6;
    time_taken = (time_taken + (t_multi_end.tv_usec - t_multi_start.tv_usec)) * 1e-6;
    printf("Time for multiple threads: %f seconds\n", time_taken);

    time_taken = (t_single_end.tv_sec - t_single_start.tv_sec) * 1e6;
    time_taken = (time_taken + (t_single_end.tv_usec - t_single_start.tv_usec)) * 1e-6;
    printf("Time for single thread: %f seconds\n", time_taken);
    return 0;
}
