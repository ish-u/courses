class stack
{
	private int stk[];
	private int tos;
	
	stack(int size)
	{
		stk = new int[size];
		tos = -1;
	}
	
	//the pop() and push() functions throws an object of type excceptionStack
	//in case of stack overflow or underflow 
	
	public void push(int a) throws stackException
	{
		if(tos == stk.length - 1)
		{
			throw new stackException(tos);
		}
		else
		{
			stk[++tos] = a;
		}
	}
	
	public int pop() throws stackException
	{
		if(tos < 0)
		{
			throw new stackException(tos);
		}
		else
		{
			return stk[tos--];
		}
	}
	
	
}