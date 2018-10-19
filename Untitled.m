close all
GOOD3=[2 2 2 1.999 1.964 1 0.036 0.001 0 0 0];
A=importdata('Matrix.dat');
[rows columns] =size(A);
dx=2/(columns-1);
dy=1/(rows-1);
POS=[0:0.1:1];
POSI=(columns-1)/2+(1+POS/dx);
VEC=A(1,POSI)
x=-1:dx:1;
y=0:dy:1;
[X Y]=meshgrid(x,y);
figure(1)
contourf(X,Y,A,'showtext','on')
xlabel('x [m]');
ylabel('y [m]');
set(gca,'FontSize',12)
figure(2)
plot(POS,GOOD3,'LineWidth',1)
hold on
plot(POS,VEC,'LineWidth',1)
grid on
xlabel('x [m]');
ylabel('y [m]');
legend('Reference results','Obtained results','location','best')
set(gca,'FontSize',12)