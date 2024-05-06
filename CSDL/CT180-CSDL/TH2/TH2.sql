create table KHOAHOC (
   MAKH                 char(4)              not null,
   TENKH                varchar(50)           not null,
   NGAYBD               date            not null,
   NGAYKT               date            not null ,
   constraint PK_KHOAHOC primary key  (MAKH),
   constraint CK_KHOAHOC  CHECK (NGAYKT>NGAYBD)
);


create table CHUONGTRINH (
   MACT                 char(5)              PRIMARY KEY,
   TENCT                varchar(100)          not null
);

create table LOAILOP (
   MALOAI               char(5)              not null  primary key,
   MACT                 char(5)              not null,
   TENLOAI              varchar(100)          not null,
   constraint FK_LOAILOP FOREIGN  key  (MACT) REFERENCES CHUONGTRINH(MACT)
);

create table LOP (
   MALOP                char(4)              not null PRIMARY KEY,
   MALOAI               char(5)              not null,
   TENLOP               varchar(50)          not null,
   SISO                 smallint             not null CHECK (SISO>12),
   MAKH   char(4)              not null,
   constraint FK1_LOP FOREIGN  key  (MALOAI) REFERENCES LOAILOP(MALOAI),
   constraint FK2_LOP FOREIGN  key  (MAKH) REFERENCES KHOAHOC(MAKH)
   
);

create table HOCVIEN (
   MAHV                 char(6)				primary key,
   TENHV                varchar(40)          not null,
   GIOITINH             smallint                  not null,
   NGAYSINH             date            not null,
   SDT                  char(10)                  not null,
   DIACHI               varchar(100)         not null
);

create table PHIEUTHU (
   SOPT                 CHAR(8)               PRIMARY KEY,
   MAHV                char(6)               not null,
   MALOP                char(4)              not null,
   NGAYLAPPHIEU         date	            not null,
   THANHTIEN        NUMERIC NOT NULL,
   constraint FK1_PT FOREIGN  key  (MAHV) REFERENCES HOCVIEN(MAHV),
   constraint FK2_PT FOREIGN  key  (MALOP) REFERENCES LOP(MALOP)
);

create table MONHOC (
   MAMH                 char(4)             PRIMARY KEY,
   TENMH                varchar(30)          not null
);



create table DIEM (
   MAMH                 char(4)              not null,
   MAHV                 char(6)                 not null,
   MALOP                char(4)              not null,
   DIEM                 float            not null CHECK(DIEM>=0),
   constraint PK_DIEM primary key  (MAMH, MAHV, MALOP),
    constraint FK1_DIEM FOREIGN  key  (MAHV) REFERENCES HOCVIEN(MAHV),
   constraint FK2_DIEM FOREIGN  key  (MALOP) REFERENCES LOP(MALOP),
   constraint FK3_DIEM FOREIGN  key  (MAMH) REFERENCES MONHOC(MAMH)
);


INSERT INTO KHOAHOC VALUES('K001','Kh a 1','2020-01-10','2020-03-20');
INSERT INTO KHOAHOC VALUES('K002','Kh a 2','2020-02-28','2020-05-28');
INSERT INTO KHOAHOC VALUES('K003','Kh a 3','2020-04-10','2020-07-20');
INSERT INTO KHOAHOC VALUES('K004','Kh a 4','2020-06-15','2020-09-20');


INSERT INTO CHUONGTRINH VALUES('CT001','Ti?ng Anh T?ng Qu t');
INSERT INTO CHUONGTRINH VALUES('CT002','Ti?ng Anh Tr? Em');
INSERT INTO CHUONGTRINH VALUES('CT003','Ti?ng Anh Luy?n K? N?ng');
INSERT INTO CHUONGTRINH VALUES('CT004','Ch??ng Tr nh TOEIC');
INSERT INTO CHUONGTRINH VALUES('CT005','Ti?ng Anh IELTS');
INSERT INTO CHUONGTRINH VALUES('CT006','Ch??ng Tr nh CamBridge');
INSERT INTO CHUONGTRINH VALUES('CT007','Ch?ng Ch? Ti?ng Anh 6 B?c(A1,B1,B2,C1)');



INSERT INTO LOAILOP VALUES('LL001','CT001','Ti?ng Anh c?n b?n');
INSERT INTO LOAILOP VALUES('LL002','CT001','Ti?ng Anh A1');
INSERT INTO LOAILOP VALUES('LL003','CT001','Ti?ng Anh A2');
INSERT INTO LOAILOP VALUES('LL004','CT001','Ti?ng Anh B1');
INSERT INTO LOAILOP VALUES('LL005','CT001','Ti?ng Anh B2');
INSERT INTO LOAILOP VALUES('LL006','CT001','Ti?ng Anh C1');
INSERT INTO LOAILOP VALUES('LL007','CT001','Ti?ng Anh C2');
INSERT INTO LOAILOP VALUES('LL008','CT001','Ti?ng Anh n ng cao');
--
INSERT INTO LOAILOP VALUES('LL009','CT002','Anh v?n nhi ??ng');
INSERT INTO LOAILOP VALUES('LL010','CT002','Anh v?n thi?u nhi');
INSERT INTO LOAILOP VALUES('LL011','CT002','Anh v?n thi?u ni n');
INSERT INTO LOAILOP VALUES('LL012','CT002','Ti?ng Anh t?ng qu t d nh cho thi?u ni n(B1)');
INSERT INTO LOAILOP VALUES('LL013','CT002','Ti?ng Anh t?ng qu t d nh cho thi?u ni n(B1+)');
INSERT INTO LOAILOP VALUES('LL014','CT002','Ti?ng Anh n ng cao');
INSERT INTO LOAILOP VALUES('LL015','CT002','IELTS');
--

INSERT INTO LOP VALUES ('L001','LL001','L?p 1','30','K001');
INSERT INTO LOP VALUES ('L002','LL001','L?p 2','30','K001');
INSERT INTO LOP VALUES ('L003','LL002','L?p 1','25','K001');





INSERT INTO HOCVIEN VALUES('HV0001','?? B nh An',1,'2000-11-02','0917217036','C? ?? - C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0002','?? Gia B?o',1,'2001-12-02','0917217036',' n M n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0003','?? Ph c Vinh',1,'2002-11-02','0917217036','C  Lao Dung - S c Tr?ng');
INSERT INTO HOCVIEN VALUES('HV0004','Th?ch Ch  T m',1,'2000-01-02','0917217036','Ch u Th nh- An Giang');


INSERT INTO HOCVIEN VALUES('HV0005','L  C?m Giao','0',to_date('2000-11-05','yyyy-mm-dd'),'0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0006','Hu?nh Gia B?o','1',to_date('2000-11-02','yyyy-mm-dd'),'0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0007','?? An Nhi n','0',to_date('2001-01-02','yyyy-mm-dd'),'0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0008','Tr?n Ho ng Uy n Anh',0,'2002-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0009','Tr?n Th nh',1,'1998-07-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0010','Tr?nh Giai Nh n',1,'2000-11-02','0917217036','Ch u Th nh- An Giang');
INSERT INTO HOCVIEN VALUES('HV0011','L  Thanh Ho ng',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0014','L  Thanh T m',1,'2002-01-17','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0015','Hu?nh Ng?c Minh',1,'2007-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0016','Ng? Ho ng Gia B?o',1,'2005-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0017','Tr?nh Ng?c Gia B?o',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0018','B i B?o Ng?c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0019','L  Ng?c Kim Kh nh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0020','L  Hu?nh My',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0021','Tr?n Ng?c Tuy?t',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0022','Tr?n Ng?c Kh nh Minh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0023','Tr?n Ng?c Minh Anh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0024','Tr?n L  Kim Ng n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0025','L  Thanh Tr n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0026','L  Thanh T m',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0027','Tr?n Ng?c Tuy?n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0028','Tr?n Hu?nh Gia Nhi',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0029','Tr?n L  Kim Thoa',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0030','B i M?ng C?m',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0031','Tr?n M?ng ?i?p',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0032','Tr?n Kim Quy n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0033','Tr?n L  Anh Th?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0034','Tr?n Thanh Nghi',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0035','Tr?n B i T? Nga',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0036','Tr?n Th? Kim C c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0037','Tr?n B?o Thy',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0038','Nguy?n Th? B?o Nghi',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0039','L  Thanh Ng?c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0040','Tr?n Th? Nh?  ',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0041','Tr?n Ng?c M?  ',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0042','Tr?n Ng?c Ph c An',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0043','Tr?n Ng?c Minh Anh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0044','Tr?n Ng?c Ph c An',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0047','Tr?n Ng?c B ch',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0048','Tr?n Thanh Nh n',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0049','?? T? Uy n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0050','L  H  My',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0051','L  Ng?c Tr n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0052','Nguy?n Minh Thi',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0053','Tr?n Ng?c Anh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0054','Tr?n Ng?c Kh nh Nh?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0055','Tr?n Ng?c Ti n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0056','Tr?n Ki?u Ti n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0057','Tr?n H?u Ph??c',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0058','Tr?n Ho ng Khang',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0059','Tr?n L m Tr??ng',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0060','Tr?n Tr?ng Ph c',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');

INSERT INTO HOCVIEN VALUES('HV0061','Tr?n Tr?ng Ngh?a',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0062','Tr?n Minh Nh?t',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0063','L  Thanh An',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0064','L  Kim Thy',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0065','Tr?n Huy?n Trang',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0066','Tr?n Minh Th?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0067','Tr?n Thanh Ng n',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0068','Nguy?n Qu?c Ki?t',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0069','L m Th? Nh?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0070','L m Minh Th?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0071','?? Ng?c Nh?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0072','Tr?n Tr?ng Ph c',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0073','Nguy?n Thanh Nh?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0074','L? Huy?n Trang',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
--
INSERT INTO HOCVIEN VALUES('HV0075','L? Anh Th?',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0076','?? H  My',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0077','?? Minh Khang',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0078','?? Ho ng Khang',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0079','?? Gia Khang',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0080','?? B i Minh Anh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0081','L  Tu?n Anh',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0082','?? Di?m Ly',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0083','?? T??ng Vy',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0084','?? Ng?c Ch c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0085','?? Minh Nh?t',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0086','?? Minh Ho ng',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0087','?? Minh Trung',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0088','?? Minh Long',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0089','V  V?n Kh nh Qu?c',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0090','Nguy?n Trung H?u',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0091','?? Lam Nh ',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0092','Hu?nh Minh S?n',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0093','H  Duy M?nh',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0094','L?u H  Ph??c',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0095','?? Ng?c Ki?u Oanh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0096','?? Gia Minh',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0097','?? Thanh Nhi',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0098','L  T?n ??t',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0099','L  Kim  nh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0100','?? Ph??ng Th y',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0101','L m Th? Th?o Linh',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0102','?? Thanh Th?o',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0103','?? Ng?c Th y',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0104','?? Ng?c Ph??ng',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0105','?? Th?ch Anh',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0106','L? T?n Anh',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0107','?? H  Giang',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');

INSERT INTO HOCVIEN VALUES('HV0108','?? Tr??ng Giang',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0109','?? H  My',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0110','?? Tu?n Ph t',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0111','?? Tu?n Ki?t',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
---
INSERT INTO HOCVIEN VALUES('HV0112','?? H  Huy',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0113','?? H  Ng?c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0114','?? Th? C?m Giang',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0115','L  B?o Trang',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0116','L  Ki?u My',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0117','Ph?m Thanh Tr c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0118','Ph?m Ng?c H ',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0119','Tr??ng Thanh Ng?c',0,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');
INSERT INTO HOCVIEN VALUES('HV0120','?? Ph?m Gia Huy',1,'2000-11-02','0917217036','Phong ?i?n- C?n Th?');










insert into PHIEUTHU values('PT000002','HV0002','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000003','HV0003','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000004','HV0004','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000005','HV0005','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000006','HV0006','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000007','HV0007','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000008','HV0008','L001','2021-06-01',1350000);
insert into PHIEUTHU values('PT000009','HV0009','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000010','HV0010','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000011','HV0011','L001','2021-06-02',1350000);
-- insert into PHIEUTHU values('PT000012','HV0012','L001','2021-06-02',1350000);
-- insert into PHIEUTHU values('PT000013','HV0013','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000014','HV0014','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000015','HV0015','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000016','HV0016','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000017','HV0017','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000018','HV0018','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000019','HV0019','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000020','HV0020','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000021','HV0021','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000022','HV0022','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000023','HV0023','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000024','HV0024','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000025','HV0025','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000026','HV0026','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000027','HV0027','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000028','HV0028','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000029','HV0029','L001','2021-06-02',1350000);
insert into PHIEUTHU values('PT000030','HV0030','L001','2021-06-02',1350000);

insert into PHIEUTHU values('PT000031','HV0031','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000032','HV0032','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000033','HV0033','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000034','HV0034','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000035','HV0035','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000036','HV0036','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000037','HV0037','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000038','HV0038','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000039','HV0039','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000040','HV0040','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000041','HV0041','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000042','HV0042','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000043','HV0043','L003','2021-06-02',1450000);
insert into PHIEUTHU values('PT000044','HV0108','L003','2021-06-05',1450000);
insert into PHIEUTHU values('PT000045','HV0109','L003','2021-06-05',1450000);
insert into PHIEUTHU values('PT000046','HV0110','L003','2021-06-05',1450000);
insert into PHIEUTHU values('PT000047','HV0111','L003','2021-06-05',1450000);
insert into PHIEUTHU values('PT000070','HV0044','L003','2021-06-05',1450000);





INSERT INTO MONHOC(MAMH,TENMH) VALUES ('MH01','Nghe');
INSERT INTO MONHOC(MAMH,TENMH) VALUES ('MH02','N i');
INSERT INTO MONHOC(MAMH,TENMH) VALUES ('MH03','??c');
INSERT INTO MONHOC(MAMH,TENMH) VALUES ('MH04','Vi?t');


INSERT INTO DIEM values  ('MH01','HV0002', 'L001', 5.5);
INSERT INTO DIEM values  ('MH02','HV0002', 'L001', 6.5);
INSERT INTO DIEM values  ('MH03','HV0002', 'L001', 8.5);
INSERT INTO DIEM values  ('MH04','HV0002', 'L001', 3.5);

INSERT INTO DIEM values  ('MH01','HV0003', 'L001', 5.25);
INSERT INTO DIEM values  ('MH02','HV0003', 'L001', 6.8);
INSERT INTO DIEM values  ('MH03','HV0003', 'L001', 7.5);
INSERT INTO DIEM values  ('MH04','HV0003', 'L001', 5.5);

INSERT INTO DIEM values  ('MH01','HV0004', 'L001', 7.5);
INSERT INTO DIEM values  ('MH02','HV0004', 'L001', 6.5);
INSERT INTO DIEM values  ('MH03','HV0004', 'L001', 7.5);
INSERT INTO DIEM values  ('MH04','HV0004', 'L001', 5.0);

INSERT INTO DIEM values  ('MH01','HV0005', 'L001', 7.5);
INSERT INTO DIEM values  ('MH02','HV0005', 'L001', 8.0);
INSERT INTO DIEM values  ('MH03','HV0005', 'L001', 8.0);
INSERT INTO DIEM values  ('MH04','HV0005', 'L001', 7.75);

INSERT INTO DIEM values  ('MH01','HV0006', 'L001', 5.5);
INSERT INTO DIEM values  ('MH02','HV0006', 'L001', 6.5);
INSERT INTO DIEM values  ('MH03','HV0006', 'L001', 4.5);
INSERT INTO DIEM values  ('MH04','HV0006', 'L001', 3.5);


--1
select * from khoahoc;
select * from hocvien;
select * from lop;
select * from loailop;
select * from phieuthu;
select * from chuongtrinh;
--2
select * from hocvien
where gioitinh=1;

--3

select * from hocvien
where diachi LIKE  '%C n Tho%';
--4
select * 
from lop l join khoahoc kh on kh.makh = l.makh 
where kh.tenkh = 'Kh a 1';

--5
select h.mahv, tenhv
from hocvien h join phieuthu p on h.mahv=p.mahv
            join lop l on l.malop=p.malop
            join khoahoc k on l.makh=k.makh
where tenkh='Kh a 1';
--6
select tenhv
from hocvien
where tenhv like '%?%'
--7
select *
from hocvien
where extract(year from ngaysinh) = 2000;
--8
select * from hocvien
where extract(year from ngaysinh)=2001 and extract(month from ngaysinh)=12;
--9
select *
from hocvien
where extract(year from ngaysinh) <= 2000 and extract(year from ngaysinh) >= 1998;
--10
select * 
from phieuthu
where ngaylapphieu between '2021-6-05' and '2021-6-10';
--11
select tenhv
from hocvien h join phieuthu pt on h.mahv = pt.mahv
            join lop l on l.malop = pt.malop
            join loailop ll on ll.maloai = l.maloai
where l.tenlop = 'L p 1' and ll.tenloai = 'Ti ng Anh can b n';
--12
select tenlop
from lop l join loailop ll on l.maloai = ll.maloai
        join chuongtrinh ct on ct.mact = ll.mact
where ct.mact = 'Ti ng Anh T ng Qu t';
--13
select sopt,mahv,pt.malop,ngaylapphieu,thanhtien
from phieuthu pt join lop l on pt.malop = l.malop
            join loailop ll on l.maloai = ll.maloai
where ll.tenloai = 'Ti ng Anh A1' and l.tenlop = 'L p 1';
--14
select h.mahv, tenhv, tenmh, diem
from hocvien h join phieuthu p on h.mahv=p.mahv
            join lop l on l.malop=p.malop
            join khoahoc k on l.makh=k.makh
            join diem d on d.mahv=h.mahv
            join monhoc m on m.mamh=d.mamh
where tenkh='Kh a 1';
--15
select count(*) sohv
from hocvien
--16
select count(tenhv) SoHocVien
from hocvien hv join phieuthu pt on pt.mahv = hv.mahv
            join lop l on l.malop = pt.malop
            join loailop ll on ll.maloai = l.maloai
where l.tenlop = 'L p 1' and ll.tenloai = 'Ti ng Anh can b n';
--17
select sum(thanhtien) tongtien
from  phieuthu p  join lop l on l.malop=p.malop
            join loailop ll on ll.maloai=l.maloai
            join khoahoc k on l.makh=k.makh
where tenlop='L p 1' and tenloai='Ti ng Anh can b n';
--18
select sum(thanhtien) TongTien
from  phieuthu p  join lop l on l.malop = p.malop
            join khoahoc k on l.makh = k.makh
where k.tenkh = 'Kh a 1';
--19
select *
from hocvien
where tenhv like '%?%'

select AVG(diem) DiemTrungBinh
from diem d join hocvien hv on d.mahv = hv.mahv
            join lop l on l.malop = d.malop
            join loailop ll on ll.maloai = l.maloai
where hv.tenhv = '? Gia B o' and hv.ngaysinh = '2001-12-02' and l.tenlop = 'L p 1'and tenloai='Ti ng Anh can b n';
--20
select MAX(diem) DiemLonNhat
from diem 