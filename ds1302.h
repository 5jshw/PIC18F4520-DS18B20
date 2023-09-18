#ifndef DS1302_h
#define DS1302_h

#define	RST			PORTAbits.RA4
#define	TRIS_RST	DDRAbits.RA4

#define	IO			PORTAbits.RA5
#define	TRIS_IO		DDRAbits.RA5

#define	SCLK		PORTEbits.RE0
#define	TRIS_SCLK	DDREbits.RE0


void ds1302_init(void); //��ʼ��
void ds1302_write(unsigned char time_tx); //д��һ���ֽ�����
unsigned char ds1302_read(void); //��ȡһ���ֽ�����
void set_time(void); //����ʱ��
void get_time_info(void); //��ȡȫ��ʱ����Ϣ
void get_time(void); //��ȡʱ��
void get_date(void); //��ȡ����
void display_date(void); //��ʾ����
void display_time(void); //��ʾʱ��

#endif