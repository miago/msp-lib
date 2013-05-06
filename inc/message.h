#ifndef __MESSAGE_H__
#define __MESSAGE_H__


//Message queue users
#define MSG_U_UART      0 
#define MSG_U_LED       1
#define MSG_U_BUTTON    2
#define MSG_U_MAIN      3

//Message queue events
#define MSG_EVT_ON      0
#define MSG_EVT_OFF     1
#define MSG_EVT_UNDEF   2
#define MSG_EVT_TOGGLE  3

//Message queue priority
#define MSG_P_0         0 //Highest
#define MSG_P_1         1 //Normal
#define MSG_P_2         2 //Lowest


typedef struct{
        char source;
        char destination;
        char priority;
        char event;
}message;

#endif