typedef BinTree SElemtype;
typedef bool Status;
typedef struct
{
	SElemtype *base;
	SElemtype *top;
	size_t StackSize;
}SqStack;

#define STACK_INIT_SIZE 10
#define STACK_INCRESEMENT 10

Status InitSqStack(SqStack &sqstack)	//��ʼ��ջ
{
	sqstack.base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if(sqstack.base == NULL) exit(EXIT_FAILURE);
	sqstack.StackSize = STACK_INIT_SIZE;
	sqstack.top = sqstack.base;
	return 0;
}

Status Push(SqStack &sqstack,const SElemtype &val)	//ѹջ
{
	if(size_t(sqstack.top - sqstack.base) >= sqstack.StackSize)
	{
		sqstack.base = (SElemtype *)realloc(sqstack.base,
			(sqstack.StackSize + STACK_INCRESEMENT) * sizeof(SElemtype));
		if(sqstack.base == NULL) exit(EXIT_FAILURE);
		sqstack.top = sqstack.base + sqstack.StackSize;
		sqstack.StackSize += STACK_INCRESEMENT;
	}
	*sqstack.top++ = val;
	return 0;
}

Status Pop(SqStack &sqstack,SElemtype &val)	//��ջ
{
	if(sqstack.base == sqstack.top) return 1;	//��ջ
	val = *--sqstack.top;
	return 0;
}

Status IsEmpty(const SqStack &sqstack)	//�ж��Ƿ�Ϊ��
{
	if(sqstack.base == sqstack.top) return TRUE;
	else return FALSE;
}

Status GetTop(const SqStack &sqstack,SElemtype &val)	//����ջ��Ԫ��
{
	if(!IsEmpty(sqstack))
	{
		val = *(sqstack.top - 1);
		return 0;
	}
	else return 1;
}

void Clear(SqStack &sqstack)	//���
{
	free(sqstack.base);
	sqstack.base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	if(sqstack.base == NULL) exit(EXIT_FAILURE);
	sqstack.top = sqstack.base;
	sqstack.StackSize = STACK_INIT_SIZE;
}