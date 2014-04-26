
void my_mouse(int b,int s,int x,int y)
{	
	if(s==GLUT_DOWN)
	{	
if(!stat_flag)
{
start_flag++;
	if(start_flag>=3)	stat_flag++;
}

		if(b==GLUT_LEFT_BUTTON)		update_box(check_box(x,y),1);	//open
	if(b==GLUT_RIGHT_BUTTON)	update_box(check_box(x,y),2);	//flag
}
}
void my_key(unsigned char key ,int x,int y)
{
	if(key==’e’)	explore_box(check_box(x,y));
}
void update_box(int b_num,int type)
{
	switch(type)
	{
		case 1:	//open
		case 2:	//flag
			if(
