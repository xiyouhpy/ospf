#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "Global_io.h"
#define SLEEPTIME 2

pthread_mutex_t imutex;
pthread_mutex_t omutex;

/***********************input队列**************************/
typedef struct iNode
{
	i_operate idata;
	struct iNode* next;
}iNode;

typedef struct {
	iNode* front;
	iNode* rear;
}iLinkQueue;

// input 队列初始化
int i_InitQueue(iLinkQueue* queue)
{
	if(!queue)
	{
		return 0;
	}
	queue->front = NULL;
	queue->rear  = NULL;
	return 1;
}

// input 入队列
void i_EnQueue(iLinkQueue* queue, i_operate e)
{
	iNode* node = (iNode *)malloc(sizeof(iNode));
	node->idata = e;
	node->next = NULL;

	// 如果队列为空
	if(queue->rear == NULL)
	{
		queue->front = node;
		queue->rear  = node;
	} else {
		queue->rear->next = node;
		queue->rear = node;
	}	
}

// input 出队列
i_operate i_DeQueue(iLinkQueue* queue)
{
	if(queue->front == NULL)
	{
		return;
	} else {
		i_operate elem;
		iNode* node = queue->front;
		elem = node->idata;
		
		if(queue->front->next == NULL)
		{
			queue->front = NULL;
			queue->rear  = NULL;
		} else {
			queue->front = queue->front->next;
		}
		free(node);
		return elem;
	}
}

// input 获得队列头元素
i_operate i_GetHead(iLinkQueue* queue)
{
	if(queue->front!=NULL)
	{
		return queue->front->idata;
	} else {
		return;
	}
}

// input 判断队列空
int i_empty(iLinkQueue* queue)
{
	if(queue->front == NULL)
	{
		return 1;
	} else {
		return 0;
	}
}

// input 求队列长度
int i_QueueLength(iLinkQueue* queue)
{
	int i = 0;
	iNode* p = queue->front;
	while(p!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

// input 清空队列
void i_ClearQueue(iLinkQueue* queue)
{
	if(queue->front == NULL)
	{
		return;
	} else {
		iNode* p = queue->front;
		iNode* q = p->next;
		while(q)
		{
			free(p);
			p = NULL;
			p = q;
			q = q->next;
		}
		free(p);
		p = NULL;
		queue->front = NULL;
		queue->rear  = NULL;
	}
}

// input 销毁队列
void i_DestroyQueue(iLinkQueue* queue)
{
	i_ClearQueue(queue);
	free(queue);
	queue = NULL;
}

// input 显示队列
void i_PrintQueue(iLinkQueue* queue)
{
	iNode* p = queue->front;
	while(p)
	{
		printf("%s ", p->idata.Inputbuffer);
		p = p->next;
	}
	printf("\n");
}


/***********************output队列**************************/
typedef struct oNode
{
	o_operate odata;
	struct oNode* next;
}oNode;

typedef struct {
	oNode* front;
	oNode* rear;
}oLinkQueue;

// output 队列初始化
int o_InitQueue(oLinkQueue* queue)
{
	queue = (oLinkQueue *)malloc(sizeof(oLinkQueue));
	if(!queue)
	{
		return 0;
	}
	queue->front = NULL;
	queue->rear  = NULL;
	return 1;
}

// output 入队列
void o_EnQueue(oLinkQueue* queue, o_operate e)
{
	oNode* node = (oNode *)malloc(sizeof(oNode));
	node->odata = e;
	node->next = NULL;

	//如果队列为空
	if(queue->rear == NULL)
	{
		queue->front = node;
		queue->rear  = node;
	} else {
		queue->rear->next = node;
		queue->rear = node;
	}	
}

// output 出队列
o_operate o_DeQueue(oLinkQueue* queue)
{
	if(queue->front == NULL)
	{
		return;
	} else {
		o_operate elem;
		oNode* node = queue->front;
		elem = node->odata;
		if(queue->front->next == NULL)
		{
			queue->front = NULL;
			queue->rear  = NULL;
		} else {
			queue->front = queue->front->next;
		}
		free(node);
		return elem;
	}
}

// output 获得队列头元素
o_operate o_GetHead(oLinkQueue* queue)
{
	if(queue->front!=NULL)
	{
		return queue->front->odata;
	} else {
		return;
	}
}

// output 判断队列空
int o_empty(oLinkQueue* queue)
{
	if(queue->front == NULL)
	{
		return 1;
	} else {
		return 0;
	}
}

// output 求队列长度
int o_QueueLength(oLinkQueue* queue)
{
	int i = 0;
	oNode* p = queue->front;
	while(p!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

// output 清空队列
void o_ClearQueue(oLinkQueue* queue)
{
	if(queue->front == NULL)
	{
		return;
	} else {
		oNode* p = queue->front;
		oNode* q = p->next;
		while(q)
		{
			free(p);
			p = NULL;
			p = q;
			q = q->next;
		}
		free(p);
		p = NULL;
		queue->front = NULL;
		queue->rear  = NULL;
	}
}

// output 销毁队列
void o_DestroyQueue(oLinkQueue* queue)
{
	o_ClearQueue(queue);
	free(queue);
	queue = NULL;
}

// output 显示队列
void o_PrintQueue(oLinkQueue* queue)
{
	oNode* p = queue->front;
	while(p)
	{
		printf("%s ", p->odata.Outputbuffer);
		p = p->next;
	}
	printf("\n");
}


// 这个是 IO 缓冲区的附加信息
typedef struct
{
	int num;	// 终端编号
	int pid;	// 线程ID
}other;


// 将缓冲区的数据读入到内核态 ibuffer 中（i 缓冲区）
int sysio_read(uint8_t *ibuffer, iLinkQueue *ibuff, other *info)
{
	i_operate temp;

	if (i_empty(ibuff)) {
		return;
	} else {
		temp = i_DeQueue(ibuff);
		strcpy(ibuffer, temp.Inputbuffer);
		info->num = temp.Inputnum;
		info->pid = temp.Inputpid;
	}
}

// 将内核态需要输出的数据 obuffer 写入缓冲区中（o 缓冲区）
void sysio_write(uint8_t *obuffer, oLinkQueue *obuff, other *info)
{
	o_operate temp;
	uint32_t len = strlen(obuffer);

	strcpy(temp.Outputbuffer, obuffer);
	temp.Outputleap = 1;
	temp.OutputSize = len;
	temp.Outputnum = info->num;
	temp.Outputpid = info->pid;
	o_EnQueue(obuff, temp);
}

// 将缓冲区数据读入到用户空间 obuffer 中（o 缓冲区）
void userio_read(uint8_t *obuffer, oLinkQueue *obuff, other *info)
{
	o_operate temp;

	if (o_empty(obuff)) {
		return;
	} else {
		temp = o_DeQueue(obuff);
		strcpy(obuffer, temp.Outputbuffer);
		info->num = temp.Outputnum;
		info->pid = temp.Outputpid;
	}
}

// 将用户空间的数据写入到缓冲区 obuffer 中（i 缓冲区）
void userio_write(uint8_t *ibuffer, iLinkQueue *ibuff, other *info)
{
	i_operate temp;
	uint32_t len = strlen(ibuffer);

	strcpy(temp.Inputbuffer, ibuffer);
	temp.Inputleap = 1;
	temp.InputSize = len;
	temp.Inputnum = info->num;
	temp.Inputpid = info->pid;
	i_EnQueue(ibuff, temp);
}




// 为线程传参组织参数
typedef struct {
	iLinkQueue *iqueue;
	oLinkQueue *oqueue;
} ioqueue;




// 这里进行模拟用户线程
void user_pthread1(void *temp)
{
	ioqueue *io = (ioqueue *)temp;
	uint32_t leap = 1;
	uint8_t output[BUFFSIZE];
	uint8_t input[BUFFSIZE];
	other info;

	info.pid = pthread_self();	// 线程ID
	info.num = 1;			// 终端号
	while (leap)
	{
		scanf("%s", input);
//		gets(input);		

		printf("\n\nuserthread(UI:%d,PID:%u)用户->(input)缓冲区 : %s\n", info.num, info.pid, input);
		pthread_mutex_lock(&imutex);
		// 用户向队列写数据
		userio_write(input, io->iqueue, &info);
		pthread_mutex_unlock(&imutex);

		// 扫描队列中是否有数据
		leap = 0;
		while (o_empty(io->oqueue))
		{
			sleep(SLEEPTIME);
		}

		pthread_mutex_lock(&omutex);
		// 从队列中获取数据
		userio_read(output, io->oqueue, &info);
		pthread_mutex_unlock(&omutex);
		printf("userthread(UI:%d,PID:%u)(output)缓冲区->用户 : %s\n", info.num, info.pid, output);

		leap = 1;
	}

}



// 这里进行模拟用户线程
void user_pthread2(void *temp)
{
	ioqueue *io = (ioqueue *)temp;
	uint32_t leap = 1;
	uint8_t output[BUFFSIZE];
	uint8_t input[BUFFSIZE];
	other info;

	info.pid = pthread_self();
	info.num = 2;
	while (leap)
	{
		scanf("%s", input);
//		gets(input);		
		
		printf("\n\nuserthread(UI:%d,PID:%u)用户->(input)缓冲区 : %s\n", info.num, info.pid, input);
		pthread_mutex_lock(&imutex);
		// 用户向队列写数据
		userio_write(input, io->iqueue, &info);
		pthread_mutex_unlock(&imutex);
		
		// 扫描队列中是否有数据
		leap = 0;
		while (o_empty(io->oqueue))
		{
			sleep(SLEEPTIME);
		}

		pthread_mutex_lock(&omutex);
		// 从队列中获取数据
		userio_read(output, io->oqueue, &info);
		pthread_mutex_unlock(&omutex);
		printf("userthread(UI:%d,PID:%u)(output)缓冲区->用户 : %s\n", info.num, info.pid, output);

		leap = 1;
	}

}



// 这里进行模拟用户线程
void user_pthread3(void *temp)
{
	ioqueue *io = (ioqueue *)temp;
	uint32_t leap = 1;
	uint8_t output[BUFFSIZE];
	uint8_t input[BUFFSIZE];
	other info;

	info.pid = pthread_self();
	info.num = 3;
	while (leap)
	{
		scanf("%s", input);
//		gets(input);		

		printf("\n\nuserthread(UI:%d,PID:%u)用户->(input)缓冲区 : %s\n", info.num, info.pid, input);
		pthread_mutex_lock(&imutex);
		// 用户向队列写数据
		userio_write(input, io->iqueue, &info);
		pthread_mutex_unlock(&imutex);
		
		// 扫描队列中是否有数据
		leap = 0;
		while (o_empty(io->oqueue))
		{
			sleep(SLEEPTIME);
		}

		pthread_mutex_lock(&omutex);
		// 从队列中获取数据
		userio_read(output, io->oqueue, &info);
		pthread_mutex_unlock(&omutex);
		printf("userthread(UI:%d,PID:%u)(output)缓冲区->用户 : %s\n", info.num, info.pid, output);

		leap = 1;
	}

}




// 这里进行模拟内核线程
void sys_pthread(void *temp)
{
	ioqueue *io = (ioqueue *)temp;
	uint32_t leap = 1;
	uint8_t input[BUFFSIZE];
	uint8_t output[BUFFSIZE];
	other info;

	info.pid = pthread_self();
	info.num = 0;
	while (leap)
	{
		// 扫描队列中是否有数据
		leap = 0;
		while (i_empty(io->iqueue))
		{
			sleep(SLEEPTIME);
		}

		pthread_mutex_lock(&imutex);
		// 从队列中获取数据
		sysio_read(input, io->iqueue, &info);
		pthread_mutex_unlock(&imutex);
		printf("systhread (UI:%d,PID:%u)(input)缓冲区->内核 : %s\n", info.num, info.pid, input);

		leap = 1;

		// 内核态处理逻辑（对用户输入的数据进行处理）
		printf("\n\n内核处理输入数据:%s\n\n", input);
		strcat(input, "(内核处理后的数据)");

		printf("systhread  (UI:%d,PID:%u)内核->(output)缓冲区 : %s\n", info.num, info.pid, input);
		pthread_mutex_lock(&omutex);
		// 用户向队列写数据
		sysio_write(input, io->oqueue, &info);
		pthread_mutex_unlock(&omutex);
	}
}




// 主程序起多个线程进行测试
int main()
{
	iLinkQueue *iqueue;
	oLinkQueue *oqueue;
	ioqueue queue;
	pthread_t userthread, systhread;
	int ret;

	pthread_t userthread1;
	pthread_t userthread2;
	pthread_t userthread3;

	iqueue = (iLinkQueue *)malloc(sizeof(iLinkQueue));
	oqueue = (oLinkQueue *)malloc(sizeof(oLinkQueue));
	
	// 队列初始化
	i_InitQueue(iqueue);
	o_InitQueue(oqueue);
	
	// 锁初始化
	pthread_mutex_init(&imutex,NULL);
	pthread_mutex_init(&omutex,NULL);

	// 组织线程函数参数
	queue.iqueue = iqueue;
	queue.oqueue = oqueue;

	ret = pthread_create(&systhread, NULL, (void *)sys_pthread, (void *)&queue);
	if (ret != 0)
	{
		printf("sys pthread create failed!\n");
		return 0;
	}
/*	ret = pthread_create(&userthread, NULL, (void *)user_pthread, (void *)&queue);
	if (ret != 0)
	{
		printf("user pthread create failed!\n");
		return 0;
	}
*/	ret = pthread_create(&userthread1, NULL, (void *)user_pthread1, (void *)&queue);
	if (ret != 0)
	{
		printf("user pthread create failed!\n");
		return 0;
	}
	ret = pthread_create(&userthread2, NULL, (void *)user_pthread2, (void *)&queue);
	if (ret != 0)
	{
		printf("user pthread create failed!\n");
		return 0;
	}
	ret = pthread_create(&userthread3, NULL, (void *)user_pthread3, (void *)&queue);
	if (ret != 0)
	{
		printf("user pthread create failed!\n");
		return 0;
	}

	pthread_join(systhread, NULL);
//	pthread_join(userthread, NULL);
	pthread_join(userthread1, NULL);
	pthread_join(userthread2, NULL);
	pthread_join(userthread3, NULL);

	i_PrintQueue(iqueue);
	o_PrintQueue(oqueue);
	
	i_DestroyQueue(iqueue);
	o_DestroyQueue(oqueue);

	return 0;
}
