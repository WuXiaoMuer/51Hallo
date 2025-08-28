#ifndef _lcd1602_H
#define _lcd1602_H

#include <STC89C5xRC.H>
#include "public.h"

//LCD1602���ݿ�4λ��8λ���壬��Ϊ1����ΪLCD1602��λ���ݿ���������֮Ϊ8λ
#define LCD1602_4OR8_DATA_INTERFACE	0	//Ĭ��ʹ��8λ���ݿ�LCD1602

//�ܽŶ���
sbit LCD1602_RS=P2^6;//��������ѡ��
sbit LCD1602_RW=P2^5;//��дѡ��
sbit LCD1602_E=P2^7; //ʹ���ź�
#define LCD1602_DATAPORT P0	//�궨��LCD1602���ݶ˿�


//��������
void lcd1602_init(void);
void lcd1602_clear(void);
void lcd1602_show_string(u8 x,u8 y,u8 *str);

#endif