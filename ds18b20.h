#ifndef	__ds18b20_h
#define	__ds18b20_h

#define DQ_DIR	DDRAbits.RA4 //方向寄存器
#define DQ		PORTAbits.RA4 //数据寄存器
#define	DQ_HIGH()	DQ_DIR = 1 //输出
#define	DQ_LOW()	DQ = 0;	DQ_DIR = 0 

//函数原型
void reset_ds18b20(void); //复位
unsigned char ack_ds18b20(void); //应答
unsigned int read_ds18b20(void); //读取
void write_ds18b20(unsigned int ku); //写入
unsigned int get_temp(void); //获取温度值
void delay_us(unsigned int us); //延时（微秒）
void delay_ms(unsigned int ms); //延时（毫秒）

//ROM命令
#define	SkipROM		0XCC //忽略ROM匹配
#define	MatchROM	0X55 //符合ROM
#define ReadROM		0X33 //读取ROM
#define SearchROM	0XF0 //搜索ROM
#define	AlarmSearch	0XEC //告警搜索

//存储器操作命令
#define	B20Convert		0X44 //开始温度转换
#define	B20WrierScr		0X4E //向RAM中写入数据
#define	B20ReadScr		0XBE //从RAM中读取数据
#define	B20CopyScr		0X48 //将RAM中数据复制到EEPROM中
#define	B20RecallEE		0XB8 //与上一条相反
#define	B20ReadPower	0XB4 //判断使用的电源模式

#endif