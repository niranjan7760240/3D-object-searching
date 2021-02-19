	


#include<GL/glut.h>
#include<stdarg.h>
#include<math.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

float angle=0,angle1=0,p3=-3.0,p1=0,p2=0,h1=0,h2=0,h3=0.7,h5=0,h6=0,h7=0,speed=0.1f;
int i=0,j=0,cd=0,v=0,t=0,h=0,p=0,r=0,s=0,o=0,z=0,q=0,dd=0,y=0,bd=0,m=0,n=0,mn[12]={0,0,0,0,0,0,0,0,0,0,0,0},mo[12]={0,0,0,0,0,0,0,0,0,0,0,0},sub1,time;

void display();
void reshape(int w,int h);
void init();
void key(unsigned char key,int x,int y);
void draw();
void search(GLint k);
void animate(int value);


void main(int argc ,char * argv[])
{
//printf("\n\nSelect left mouse button for menus\n\n");

printf("Select Object by using following alphabets::\n");
printf("Objects\t\tAlphabet\n");
printf("Cube\t\t'c'\n"); 
printf("Teapot\t\t't'\n");
printf("Torus\t\t'z'\n");
printf("Pentagon\t\tp\n");
//printf("Dodecahedran\t\t\n");
printf("Tetrahedron\t\tq\n");
printf("Rectangular Cube\tv\n");
printf("Vertical Cube\t\n");
printf("Rhombus\t\tr\n");
printf("Cone\t\to\n");
printf("Hexagon\t\th\n");
printf("Sphere\t\ts\n");
printf("\n\n");
printf("Click Mouse Right for search an object\n\n");
printf("use ',' & '.' and '<' & '>'\n\n");

printf("enter the number of objects(maximum of 12 objects)\n");
scanf("%d",&n);
while(1) {
if(n>12) {
printf("Enterno. below 12\n");
scanf("%d",&n);
if(n<=12)
	break;
}
}
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

/*glutInitWindowPosition(30,20);
glutInitWindowSize(600,480);
glutCreateWindow("Objects1");*/

glutInitWindowPosition(0,0);
glutInitWindowSize(600,480);
glutCreateWindow("Objects");
glutReshapeFunc(reshape);
glutKeyboardFunc(key);
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glutDisplayFunc(display);
glutTimerFunc(1.0, animate,0);
glutPostRedisplay();


 sub1=glutCreateMenu(search);//acc
glutAddMenuEntry("cube",1);
glutAddMenuEntry("rectangle",2);
glutAddMenuEntry("teapot",3);
glutAddMenuEntry("hexagon",4);
glutAddMenuEntry("pentagon",5);
glutAddMenuEntry("rhombus",6);
glutAddMenuEntry("sphere",7);
glutAddMenuEntry("cone",8);
glutAddMenuEntry("torus",9);
glutAddMenuEntry("tetrahedron",10);
glutAddMenuEntry("triangle",11);
//glutAddMenuEntry("vertical cube",12);
glutCreateMenu(search);
glutAddSubMenu("Search Objects",sub1);
glutAddMenuEntry("Terminate",13);

glutAttachMenu(GLUT_RIGHT_BUTTON);


init();
glutMainLoop();
}

void animate(int value) {
glutTimerFunc(speed, animate,0);
time++;
if(time>=10)
time=0;
glutPostRedisplay();
}

void init()
{
glClearColor(0,0,0,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45,640/480,1.0,500.0);
glMatrixMode(GL_MODELVIEW);
}
void reshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,2,20);
else
glFrustum(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2,2,20);
glMatrixMode(GL_MODELVIEW);
glShadeModel(GL_SMOOTH);
glutPostRedisplay();
}


void display()
{
GLfloat b[]={0.6,0.8,0.6,0.8};
GLfloat c[]={-0.7,-1.1,5.0,0};
GLfloat d[]={0.4,0.8,0.8,19.3};
//GLfloat e[]={1,0,0,1};
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glClearColor(0,0,0,1);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glMaterialfv(GL_FRONT,GL_AMBIENT,b);
glMaterialfv(GL_BACK,GL_AMBIENT,b);
//glMaterialfv(GL_FRONT,GL_DIFFUSE,e);
glLightfv(GL_LIGHT0,GL_POSITION,c);
glLightfv(GL_LIGHT0,GL_INTENSITY,d);
//glMaterialfv(GL_FRONT, GL_SHININESS, d);
//glColor3f(1,0,0);
//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//glClearColor(0,0,0,1);
//glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();

if(t==1){
glPushMatrix();
glTranslatef(-4.099998,-2.700000,-5.099998);
if(mo[2]==1) {
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidTeapot(1.0);
//}
}
else
glutWireTeapot(1.0);
glPopMatrix();
}
if(cd==1){
glPushMatrix();
glTranslatef(-0.8,-2.300000,-4.1);
if(mo[0]==1){
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidCube(1.0);
//}
}
else
glutWireCube(1.0);
glPopMatrix();
}

if(h==1){ //acc
glPushMatrix();
glTranslatef(-0.800000,-0.300000,-4.499999); //6
if(mo[3]==1) {
//if(time>5){
glRotatef(angle, 1, 0, 0);
glutSolidSphere(1.0,6,6);
//}
}
else
glutWireSphere(1.0,6,6);
glPopMatrix();
}

if(p==1){//acc
glPushMatrix();
glTranslatef(1.500000,-0.300000,-4.499999); //5 
if(mo[4]==1) {
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidSphere(1.0,5,5);
//}
}
else
glutWireSphere(1.0,5,5);
glPopMatrix();
}
if(r==1){//acc
glPushMatrix();
glTranslatef(0.300000,1.800000,-4.499999); //4 
if(mo[5]==1) {
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidSphere(1.0,4,4);
//}
}
else
glutWireSphere(1.0,4,4);
glPopMatrix();
}
if(s==1){//acc
glPushMatrix();
glTranslatef(-3.299999,-0.200000,-4.499999); //100
if(mo[6]==1) {
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidSphere(1.0,25,25);
//}
}
else
glutWireSphere(1.0,25,25);
glPopMatrix();
}
if(o==1){//acc
glPushMatrix();
glTranslatef(-2.000000,1.800000,-4.499999);// cone acc
glRotatef(-81.899323,1,0,0);
//if(mo[7]==1){
if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidCone(1,1,25,25);
//}
}
else
glutWireCone(1,1,25,25);
glPopMatrix();
}
if(z==1){//acc
glPushMatrix();
glTranslatef(1.400000,-2.600000,-4.499999);// ll acc  
glRotatef(-60.899643,1,0,0);
if(mo[8]==1){
if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidTorus(0.35,0.6,25,25);
}
}
else
glutWireTorus(0.35,0.6,25,25);
glPopMatrix();
}
// 1 acc
if(q==1){//acc
glPushMatrix();
glTranslatef(2.500000,1.900000,-4.499999);// ll acc  
if(mo[9]==1){
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidTetrahedron();
}
//}
else
glutWireTetrahedron();
glPopMatrix();
}
//2 acc
if(v==1){//acc
glPushMatrix();
glTranslatef(3.899998,-2.700000,-4.499999);
glScalef(1.8,1,1);
if(mo[1]==1){
//if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidCube(1.0);// acc rectangle
}
//}
else
glutWireCube(1.0);
glPopMatrix();
}
if(dd==1){//acc
glPushMatrix();
glTranslatef(3.099999,-0.300000,-3.499999);
if(mo[10]==1){
if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidTorus(0.35,0.6,3,3);
}
}
else
glutWireTorus(0.35,0.6,3,3);
glPopMatrix();
}
/*if(y==1){//acc
glPushMatrix(); //-4.399998,2.100000,-4.499999
glTranslatef(-4.399998,2.100000,-4.499999); //100
glutSolidTorus(0.35,0.6,8,8);
glPopMatrix();
}*/
if(bd==1){//acc
glPushMatrix();
glTranslatef(4.499998,2.100000,-4.499999); //stick acc
glScalef(0.2,1.3,0.2);
if(mo[11]==1){
if(time>5){
glRotatef(angle, 1, 0, 0);
glRotatef(angle1, 0,1,0);
glutSolidCube(1.0);
}
}
else
glutWireCube(1.0);
glPopMatrix();
}
glFlush();
glutSwapBuffers();
//angle+=5;
glutPostRedisplay();
}

void key(unsigned char key,int x,int y)
{

if(key=='i')
{
p2-=-0.1;
glutPostRedisplay();
}
if(key=='k')
{
p2-=0.1;
glutPostRedisplay();
}
if(key=='l')
{
p1-=-0.1;
glutPostRedisplay();
}
if(key=='j')
{
p1-=0.1;
glutPostRedisplay();
}
//1
if((key=='c'&&m<n)&&mn[0]==0) //0
{
cd=1;
mn[0]=1;
m-=-1;
glutPostRedisplay();
}
if((key=='C'&&m>0)&&mn[0]==1)
{
cd=0;
m-=1;
mn[0]=0;
glutPostRedisplay();
}
if((key=='v'&&m<n)&&mn[1]==0)//1
{
v=1;
mn[1]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='V'&&m>0)&&mn[1]==1)
{
v=0;
mn[1]=0;
m-=1;
glutPostRedisplay();
}

if((key=='t'&&m<n)&&mn[2]==0)//2          
{
t=1;
mn[2]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='T'&&m>0)&&mn[2]==1)          
{
t=0;
m-=1;
mn[2]=0;
glutPostRedisplay();
}

if((key=='h'&&m<n)&&mn[3]==0)//3
{
h=1;
mn[3]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='H'&&m>0)&&mn[3]==1)
{
h=0;
m-=1;
mn[3]=0;
glutPostRedisplay();
}

if((key=='p'&&m<n)&&mn[4]==0)//4
{
p=1;
mn[4]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='P'&&m>0)&&mn[4]==1)
{
p=0;
m-=1;
mn[4]=0;
glutPostRedisplay();
}
//c=0,v=0,t=0,h=0,p=0,r=0,s=0,o=0,z=0,q=0,d=0,y=0,b=0;
if((key=='r'&&m<n)&&mn[5]==0)  //5
{
r=1; 
mn[5]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='R'&&m>0)&&mn[5]==1)  
{
r=0;
m-=1;
mn[5]=0;
glutPostRedisplay();
}

if((key=='s'&&m<n)&&mn[6]==0)//6
{
s=1;
mn[6]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='S'&&m>0)&&mn[6]==1)
{
s=0;
m-=1;
mn[6]=0;
glutPostRedisplay();
}



if((key=='o'&&m<n)&&mn[7]==0)//7
{
o=1;
mn[7]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='O'&&m>0)&&mn[7]==1)
{
o=0;
m-=1;
mn[7]=0;
glutPostRedisplay();
}


if((key=='z'&&m<n)&&mn[8]==0)//8
{
z=1;
mn[8]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='Z'&&m>0)&&mn[8]==1)
{
z=0;
m-=1;
mn[8]=0;
glutPostRedisplay();
}



if((key=='q'&&m<n)&&mn[9]==0)//9
{
q=1;
mn[9]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='Q'&&m>0)&&mn[9]==1)
{
q=0;
m-=1;
mn[9]=0;
glutPostRedisplay();
}

if((key=='d'&&m<n)&&mn[10]==0)//10
{
dd=1;
mn[10]=1;
m-=-1;
glutPostRedisplay();
}

if((key=='D'&&m>0)&&mn[10]==1)
{
dd=0;
m-=1;
mn[10]=0;
glutPostRedisplay();
}
if((key=='b'&&m<n)&&mn[11]==0)//11
{
bd=1;
mn[11]=1;
m-=-1;
glutPostRedisplay();
}
if((key=='B'&&m>0)&&mn[11]==1)
{
bd=0;
m-=1;
mn[11]=0;
glutPostRedisplay();
}
//for(i=0;i<12;i-=-1)
if(key=='.')
angle+=2;
if(key==',')
angle-=2;
if(key=='>')
angle1+=3;
if(key=='<')
angle1-=3;
}
void search(GLint k)
{
for(i=0;i<n;i-=-1)
mo[i]=0;
switch(k)
{
case 1:j=0;
break;
case 2:j=1;
break;
case 3:j=2;
break;
case 4:j=3;
break;
case 5:j=4;
break;
case 6:j=5;
break;
case 7:j=6;
break;
case 8:j=7;
break;
case 9:j=8;
break;
case 10:j=9;
break;
case 11:j=10;
break;
case 12:j=11;
break;
case 13 : exit(0);
}
for(i=0;i<=j;i-=-1)
{
if((i==j)&&mn[j]==1)
{
mo[j]=1;
glutPostRedisplay();
}
}
}


