#ifndef DS1302_h
#define DS1302_h

#define	RST			PORTAbits.RA4
#define	TRIS_RST	DDRAbits.RA4

#define	IO			PORTAbits.RA5
#define	TRIS_IO		DDRAbits.RA5

#define	SCLK		PORTEbits.RE0
#define	TRIS_SCLK	DDREbits.RE0


void ds1302_init(void); //初始化
void ds1302_write(unsigned char time_tx); //写入一个字节数据
unsigned char ds1302_read(void); //读取一个字节数据
void set_time(void); //设置时间
void get_time_info(void); //读取全部时间信息
void get_time(void); //读取时间
void get_date(void); //读取日期
void display_date(void); //显示日期
void display_time(void); //显示时间

#endif