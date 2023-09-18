#ifndef	__ds18b20_h
#define	__ds18b20_h

#define DQ_DIR	DDRAbits.RA4 //����Ĵ���
#define DQ		PORTAbits.RA4 //���ݼĴ���
#define	DQ_HIGH()	DQ_DIR = 1 //���
#define	DQ_LOW()	DQ = 0;	DQ_DIR = 0 

//����ԭ��
void reset_ds18b20(void); //��λ
unsigned char ack_ds18b20(void); //Ӧ��
unsigned int read_ds18b20(void); //��ȡ
void write_ds18b20(unsigned int ku); //д��
unsigned int get_temp(void); //��ȡ�¶�ֵ
void delay_us(unsigned int us); //��ʱ��΢�룩
void delay_ms(unsigned int ms); //��ʱ�����룩

//ROM����
#define	SkipROM		0XCC //����ROMƥ��
#define	MatchROM	0X55 //����ROM
#define ReadROM		0X33 //��ȡROM
#define SearchROM	0XF0 //����ROM
#define	AlarmSearch	0XEC //�澯����

//�洢����������
#define	B20Convert		0X44 //��ʼ�¶�ת��
#define	B20WrierScr		0X4E //��RAM��д������
#define	B20ReadScr		0XBE //��RAM�ж�ȡ����
#define	B20CopyScr		0X48 //��RAM�����ݸ��Ƶ�EEPROM��
#define	B20RecallEE		0XB8 //����һ���෴
#define	B20ReadPower	0XB4 //�ж�ʹ�õĵ�Դģʽ

#endif