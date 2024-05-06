CREATE TABLE TACPHAM(
	NT 		smallint primary key ,
	tua 		varchar(150),
	tacgia 		varchar(100)
) ;

CREATE TABLE DOCGIA (
	ND		smallint PRIMARY KEY ,
	ho		VARCHAR(30),
	ten		VARCHAR(30),
	dchi	VARCHAR(100),
	tel		CHAR(10)
) ;

CREATE TABLE SACH (
	NS		smallint primary key ,
	nxb		varchar(50),
	NT		smallint not null, 
 	foreign key(NT) references TACPHAM(NT)
);

CREATE TABLE MUON (
	NS		smallint not NULL, 
	foreign key(NS) references SACH(NS),
	ngaymuon	date not NULL,
	hantra	date not null,
	ngaytra 	date,
	ND		smallint not null, 
	foreign key(ND) references DOCGIA(ND),
	primary key 	(NS, ngaymuon)
) ;


INSERT INTO TACPHAM VALUES (1,'Les miserables','Victor Hugo');
INSERT INTO TACPHAM VALUES (2,'Germinal ','Emile Zola');
INSERT INTO TACPHAM VALUES (3,'Madame Bovary','Gustave Flaubert');
INSERT INTO TACPHAM VALUES (4,'Les Fleurs du mal','Charles Baudelaire');
INSERT INTO TACPHAM VALUES (5,'La Bete Humaine','Emile Zola');
INSERT INTO TACPHAM VALUES (6,'Le Pere Goriot ','Honore de Balzac');
INSERT INTO TACPHAM VALUES (7,'Le Rouge et le Noir','Stendhal');
INSERT INTO TACPHAM VALUES (8,'Une vie','Guy de Maupassant');
INSERT INTO TACPHAM VALUES (9,'Ubu Roi','Alfred Jarry');
INSERT INTO TACPHAM VALUES (10,'Po?e','Arthur Rimbaud');
INSERT INTO TACPHAM VALUES (11,'La Mare au Diable','George Sand');
INSERT INTO TACPHAM VALUES (12,'Carmen','Prosper Merimee');
INSERT INTO TACPHAM VALUES (13,'Lettres de mon moulin','Alphonse Daudet');
INSERT INTO TACPHAM VALUES (14,'Les contes du chat perch ', 'Marcel Ayme');
INSERT INTO TACPHAM VALUES (15,'La Peste','Albert Camus');
INSERT INTO TACPHAM VALUES (16,'Le petit prince','Antoine de St Exupery');


INSERT INTO DOCGIA VALUES (1,'Lecoeur','Jeanette','16 rue de la R?blique, 75010 Paris','0145279274');
INSERT INTO DOCGIA VALUES (2,'Lecoeur','Philippe','16 rue de la R?blique, 75010 Paris','0145279274');
INSERT INTO DOCGIA VALUES (3,'Dupont','Yvan','73 rue Lamarck, 75018 Paris','0163538294');
INSERT INTO DOCGIA VALUES (4,'Mercier','Claude','155 avenue Parmentier, 75011 Paris','0136482736');
INSERT INTO DOCGIA VALUES (5,'L?r','Marc','90 avenue du Maine, 75014 Paris','0164832947');
INSERT INTO DOCGIA VALUES (6,'Martin','Laure','51 boulevard Diderot, 75012 Paris','0174693277');
INSERT INTO DOCGIA VALUES (7,'Crozier','Martine','88 rue des Portes Blanches, 75018 Paris','0146829384');
INSERT INTO DOCGIA VALUES (8,'Lebon','Cl?nt','196 boulevard de Sebastopol, 75001 Paris','0132884739');
INSERT INTO DOCGIA VALUES (9,'Dufour','Jacques','32 rue des Alouettes, 75003 Paris','0155382940');
INSERT INTO DOCGIA VALUES (10,'Dufour','Antoine','32 rue des Alouettes, 75003 Paris','0155382940');
INSERT INTO DOCGIA VALUES (11,'Dufour','St?anie','32 rue des Alouettes, 75003 Paris','0155382940');
INSERT INTO DOCGIA VALUES (12,'Raymond','Carole','35 rue Oberkampf, 75011 Paris','0153829402');
INSERT INTO DOCGIA VALUES (13,'Durand','Albert','4 rue Mandar, 75002 Paris','0642374021');
INSERT INTO DOCGIA VALUES (14,'Wilson','Paul','12 rue Paul Vaillant Couturier, 92400 Montrouge','0642327407');
INSERT INTO DOCGIA VALUES (15,'Grecault','Philippe','15 rue de la Roquette, 75012 Paris','0132762983');
INSERT INTO DOCGIA VALUES (16,'Carre','St?ane','51 boulevard Diderot, 75012 Paris','0174693277');
INSERT INTO DOCGIA VALUES (17,'Johnson','Astrid','3 rue L? Blum, 75002 Paris','0143762947');
INSERT INTO DOCGIA VALUES (18,'Mirou','Caroline','2 square Mirabeau, 75011 Paris','0163827399');
INSERT INTO DOCGIA VALUES (19,'Espelette','Jean-Jacques','141 avenue de France, 75019 Paris','0134887264');
INSERT INTO DOCGIA VALUES (20,'Despentes','Anthony','56 boulevard de la Villette, 75019 Paris','0133889463');
INSERT INTO DOCGIA VALUES (21,'Terlu','V?nique','45 rue des Batignolles, 75020 Paris','0165998372');
INSERT INTO DOCGIA VALUES (22,'Rihour','C?le','7 rue Montorgueil, 75002 Paris','0166894754');
INSERT INTO DOCGIA VALUES (23,'Franchet','Pierre','160 rue Montmartre, 75009 Paris','0633628549');
INSERT INTO DOCGIA VALUES (24,'Trochet','Ernest','34 rue de l''Esperance, 75008 Paris','0638295563');
INSERT INTO DOCGIA VALUES (25,'Gainard','Simon','55 rue Desnouettes, 75015 Paris','0174928934');
INSERT INTO DOCGIA VALUES (26,'Touche','Johanna','14 rue du Bac, 75006 Paris','0619384065');
INSERT INTO DOCGIA VALUES (27,'Cornu','Sylvain','22 rue Mouffetard, 75005 Paris','0184927489');
INSERT INTO DOCGIA VALUES (28,'Frederic','Cyril','15 rue du Simplon, 75018 Paris','0173625492');
INSERT INTO DOCGIA VALUES (29,'Crestard','Cedric','5 rue Doudeauville, 75018 Paris','0629485700');
INSERT INTO DOCGIA VALUES (30,'Le Bihan','Karine','170 bis rue Ordener, 75018 Paris','0638995221');


INSERT INTO SACH VALUES (1,'GF',1);
INSERT INTO SACH VALUES (2,'FOLIO',2);
INSERT INTO SACH VALUES (3,'HACHETTE',3);
INSERT INTO SACH VALUES (4,'GF',4);
INSERT INTO SACH VALUES (5,'FOLIO',5);
INSERT INTO SACH VALUES (6,'FOLIO',6);
INSERT INTO SACH VALUES (7,'GF',7);
INSERT INTO SACH VALUES (8,'FOLIO',8);
INSERT INTO SACH VALUES (9,'HACHETTE',9);
INSERT INTO SACH VALUES (10,'GF',10);
INSERT INTO SACH VALUES (11,'HACHETTE',11);
INSERT INTO SACH VALUES (12,'FOLIO',12);
INSERT INTO SACH VALUES (13,'GF',13);
INSERT INTO SACH VALUES (14,'FOLIO',14);
INSERT INTO SACH VALUES (15,'HACHETTE',15);
INSERT INTO SACH VALUES (16,'HACHETTE',16);
INSERT INTO SACH VALUES (17,'GF',1);
INSERT INTO SACH VALUES (18,'FOLIO',2);
INSERT INTO SACH VALUES (19,'HACHETTE',2);
INSERT INTO SACH VALUES (20,'FOLIO',4);
INSERT INTO SACH VALUES (21,'GF',5);
INSERT INTO SACH VALUES (22,'HACHETTE',4);
INSERT INTO SACH VALUES (23,'HACHETTE',7);
INSERT INTO SACH VALUES (24,'FOLIO',8);
INSERT INTO SACH VALUES (25,'GF',1);
INSERT INTO SACH VALUES (26,'HACHETTE',10);
INSERT INTO SACH VALUES (27,'FOLIO',11);
INSERT INTO SACH VALUES (28,'FOLIO',12);
INSERT INTO SACH VALUES (29,'GF',1);
INSERT INTO SACH VALUES (30,'HACHETTE',14);

INSERT INTO MUON VALUES (1,'9-2-2007','9-16-2007','9-7-2007',1);
INSERT INTO MUON VALUES (1,'10-1-2006','10-15-2006','10-11-2006',26);
INSERT INTO MUON VALUES (1,'6-14-2007','6-28-2007','6-19-2007',2);

INSERT INTO MUON VALUES (1,'4-27-2007','5-11-2007','5-8-2007',3);
INSERT INTO MUON VALUES (2,'8-23-2007','9-6-2007','9-2-2007',4);
INSERT INTO MUON VALUES (2,'10-6-2007','10-20-2007', NULL,28);

INSERT INTO MUON VALUES (9,'10-6-2007','10-20-2007', NULL,28);
INSERT INTO MUON VALUES (3,'9-9-2007','9-23-2007','9-13-2007',3);
INSERT INTO MUON VALUES (4,'2-8-2007','2-22-2007','2-12-2007',12);
INSERT INTO MUON VALUES (4,'2-7-2006','2-21-2006','2-20-2006',4);

INSERT INTO MUON VALUES (4,'6-17-2007','7-1-2007','6-27-2007',5);
INSERT INTO MUON VALUES (5,'10-4-2007','10-19-2007', NULL,16);
INSERT INTO MUON VALUES (6,'3-11-2007','3-25-2007','3-16-2007',3);

INSERT INTO MUON VALUES (8,'7-14-2007','7-28-2007','7-20-2007',18);
INSERT INTO MUON VALUES (8,'3-9-2007','3-23-2007','3-27-2007',13);

INSERT INTO MUON VALUES (10,'4-11-2007','4-25-2007','4-23-2007',8);
INSERT INTO MUON VALUES (10,'1-27-2006','2-10-2006','1-31-2006',7);
INSERT INTO MUON VALUES (11,'10-1-2007','10-15-2007', NULL,22);

INSERT INTO MUON VALUES (12,'3-3-2003','3-17-2003','3-13-2003',7);
INSERT INTO MUON VALUES (14,'10-2-2007','10-16-2007', NULL,1);
INSERT INTO MUON VALUES (15,'5-4-2007','5-18-2007','5-12-2007',10);

INSERT INTO MUON VALUES (16,'10-5-2007','10-19-2007', NULL,2);
INSERT INTO MUON VALUES (18,'7-4-2007','7-18-2007','7-11-2007',3);
INSERT INTO MUON VALUES (20,'12-17-2006','12-31-2006','12-17-2006',27);

INSERT INTO MUON VALUES (20,'9-6-2007','9-20-2007','9-22-2007',9);
INSERT INTO MUON VALUES (21,'9-7-2007','9-21-2007','9-19-2007',14);
INSERT INTO MUON VALUES (24,'2-14-2007','2-28-2007','2-20-2007',26);
INSERT INTO MUON VALUES (25,'8-19-2006','9-2-2006','9-3-2006',1);
INSERT INTO MUON VALUES (26,'11-15-2006','11-29-2006','11-22-2006',9);
INSERT INTO MUON VALUES (29,'9-20-2007','10-4-2007', NULL,27);

--1) Xem d? li?u c?a t?t c? c c b?ng
SELECT * FROM docgia;
SELECT * FROM muon;
SELECT * FROM sach;
SELECT * FROM tacpham;
--2) V? s? ?? li n th ng
--B?ng TACPHAM li n k?t v?i b?ng SACH th ng qua tr??ng NT, ??i di?n cho t c ph?m.
--B?ng SACH l?u th ng tin v? s ch, bao g?m ng y t i b?n (nxb) v  t c ph?m (NT).
--B?ng DOCGIA l?u th ng tin v? ??c gi?, bao g?m h? (ho), t n (ten), ??a ch? (dchi), v  s? ?i?n tho?i (tel).
--B?ng MUON l?u th ng tin v? m??n s ch, bao g?m s ch (NS), ng y m??n (ngaymuon), h?n tr? (hantra), ng y tr? (ngaytra), v  ??c gi? (ND).
--3) C c t c ph?m (NT, t?a) c?a t c gi? 'Guy de Maupassant'.
SELECT nt,tua
FROM tacpham
WHERE tacgia = 'Guy de Maupassant';
--4) C c ??c gi? s?ng ? ??a ch? '32 rue des Alouettes, 75003 Paris'.
SELECT *
FROM docgia
WHERE dchi LIKE '32 rue des Alouettes, 75003 Paris';
--5) T m t n nh  xu?t b?n c c t c ph?m bao g?m t? 'Fleur'
SELECT DISTINCT s.nxb
FROM tacpham t
JOIN sach s
ON t.nt = s.nt
WHERE t.tua LIKE '%Fleur%';
--6) T m t n c c t c ph?m b?t ??u b?ng 'Le'
SELECT tua
FROM tacpham
WHERE tua LIKE 'Le%';
SELECT tua FROM tacpham WHERE tua LIKE 'Le %';
--7) T m t n c c ??c gi? c  m??n s ch trong trong kho?ng th?i gian t? ng y 15/9/2007 ??n
--20/09/2007
SELECT DISTINCT d.ten
FROM muon m
JOIN docgia d
ON m.nd = d.nd
WHERE ( m.ngaymuon >= '9/15/2007'
AND m.ngaymuon <= '9/20/2007' );
--8) Nh  xu?t b?n c?a t c ph?m ti u ?? 'Germinal'.
SELECT DISTINCT s.nxb
FROM tacpham t
JOIN sach s
ON t.nt = s.nt
WHERE t.tua LIKE '%Germinal%';
--9) T n ??c gi? ?  m??n t c ph?m 'Po sie'.
SELECT DISTINCT d.ten
FROM docgia d
JOIN muon m
ON m.nd = d.nd
JOIN sach s
ON s.ns = m.ns
JOIN tacpham t
ON t.nt = s.nt
WHERE t.tua LIKE '%Po sie%';
--select * from docgia;
--select * from muon;
--select * from sach;
--select * from tacpham;
--10) Nh?ng ??c gi? n o ?  m??n t c ph?m Les 'Fleurs du mal'
SELECT DISTINCT d.ho,d.ten
FROM docgia d
JOIN muon m
ON m.nd = d.nd
JOIN sach s
ON s.ns = m.ns
JOIN tacpham t
ON t.nt = s.nt
WHERE t.tua LIKE '%Les Fleurs du mal%';
--11) T m c c t?a s ch, t n ??c gi? c?a c c ??c gi? tr? s ch qu  th?i h?n cho ph p
SELECT DISTINCT t.tua, d.ten
FROM muon m
JOIN docgia d
ON d.nd = m.nd
JOIN sach s
ON s.ns = m.ns
JOIN tacpham t
ON t.nt = s.nt
WHERE ( m.ngaytra > m.hantra );
--12) T m c c t?a s ch, t n ??c gi? c?a c c ??c gi? tr? s ch tr??c th?i h?n
SELECT DISTINCT t.tua,d.ten
FROM muon m
JOIN docgia d
ON d.nd = m.nd
JOIN sach s
ON s.ns = m.ns
JOIN tacpham t
ON t.nt = s.nt
WHERE ( m.ngaytra <= m.hantra );
--13) T n ??c gi? ?  m??n t c ph?m c?a 'Victor Hugo'
SELECT DISTINCT d.ten
FROM docgia d
JOIN muon m
ON m.nd = d.nd
JOIN sach s
ON s.ns = m.ns
JOIN tacpham t
ON t.nt = s.nt
WHERE t.tacgia LIKE '%Victor Hugo%';
--14) T n ??c gi? v  c c t c ph?m ?  ???c m??n n?m 2007
SELECT DISTINCT d.ten,
  t.tua,
  t.tacgia
FROM muon m
JOIN docgia d
ON d.nd = m.nd
JOIN sach s
ON s.ns = m.ns
JOIN tacpham t
ON t.nt= s.nt
WHERE EXTRACT(YEAR FROM m.ngaymuon) = 2007;
--15) T nh s? t c ph?m c  trong th? vi?n.
SELECT COUNT(tua) AS sotacpam
FROM tacpham;

--16) T?a c?a t c ph?m m  c   t nh?t hai quy?n s ch.
select t.nt, tua, count(*) sosach
from sach s join tacpham t on t.nt=s.nt
group by t.nt, tua HAVING count(*) >1
order by t.nt
--17) T nh S? t c ph?m c?a m?i t c gi?.

select tacgia, count(*) sotp
from tacpham
group by tacgia
--18) T nh S? s ch c?a m?i t c ph?m.

select t.nt, tua, count(*) sosach
from sach s join tacpham t on t.nt=s.nt
group by t.nt, tua
order by t.nt
--19) T m s? l?n m??n s ch c?a m?i ??c gi? theo n?m

select nd, extract(year from ngaymuon) nam ,count(*) solanmuon
from muon
group by nd, extract(year from ngaymuon)
order by nd

select nd, count(*) solanmuon
from muon
where extract(year from ngaymuon)=2007
group by nd
order by nd
--20) T m t n t c ph?m c   t nh?t 3 s ch

select tua, t.nt, count(*) sosach
from sach s join tacpham t on t.nt = s.nt
GROUP BY tua, t.nt HAVING count(*) >=  3
order by t.nt;
--21) T m t n t c ph?m c  nhi?u s ch nh?t

 CREATE TABLE c21 as
    select t.nt, tua, count(*) sosach
    from sach s join tacpham t on t.nt=s.nt
    group by t.nt, tua
    order by t.nt;
  select *
  from c21
  where sosach= (select max(sosach) from c21);
  drop table c21;
  
  -- cach 2

   select t.nt, tua, count(*) sosach
    from sach s join tacpham t on t.nt=s.nt
    group by t.nt, tua having count(*)=(    select max(count(*)) from sach group by nt)
-- 22) T n nh  xu?t b?n xu?t b?n nhi?u s ch nh?t

select nxb, nt, count (*) sosach
from sach
GROUP BY nxb, nt having count(*) = (select max(count(*)) from sach group by nt )
-- 23) T nh S? t c gi? c   t nh?t hai t c ph?m

CREATE TABLE c23 as
  select s.nt, tacgia,  count (*) sosach
  from sach s join tacpham tp on s.nt = tp.nt
  GROUP BY s.nt, tacgia Having count(*) >= 2
  order by s.nt

select all count(*) sotacgia
from c23
--24) T m t?a t c ph?m c  nhi?u ng??i m??n nh?t
select tua,s.ns, count(*) luotmuon
from muon m join sach s on s.ns = m.ns
      join tacpham tp on tp.nt = s.nt
group by tua, s.ns having count(*) = (select max(count(*)) from muon group by ns)
order by luotmuon desc
--25) T m t?a t c ph?m c   t ng??i m??n nh?t
select tua,s.ns, count(*) luotmuon
from muon m join sach s on s.ns = m.ns
      join tacpham tp on tp.nt = s.nt
group by tua, s.ns having count(*) = (select min(count(*)) from muon group by ns)
order by luotmuon desc
--26) T m ??c gi? m??n nhi?u t c ph?m nh?t
select dg.nd,ho,ten,dchi,tel, count(*) luotmuonsach
from docgia dg join muon m on dg.nd = m.nd
group by dg.nd,ho,ten,dchi,tel having count(*) = (select max(count(*)) from muon group by nd)
--27) T m t n ??c gi? m??n  t t c ph?m nh?t
select dg.nd,ho,ten,dchi,tel, count(*) luotmuonsach
from docgia dg join muon m on dg.nd = m.nd
group by dg.nd,ho,ten,dchi,tel having count(*) = (select min(count(*)) from muon group by nd)

--28) T m t n t c ph?m c   t nh?t m?t quy?n s ch kh ng ai m??n

select t.nt,tua
from tacpham t join sach s on t.nt=s.nt left join muon m on s.ns=m.ns
where ngaymuon is null;

select tua from tacpham t join sach s on t.nt=s.nt 
where ns NOT IN (select ns from muon)
--29) T m t n t c ph?m c  t?t c? c c quy?n s ch ??u ???c m??n

select tua
from tacpham 
where nt NOT IN (select nt
                from  sach s  left join muon m on s.ns=m.ns
                where ngaymuon is null)
--30) T m h? t n ??c gi? ch?a m??n quy?n s ch n o
select dg.nd,ho,ten
from docgia dg 
minus 
select dg.nd,ho,ten
from docgia dg join muon m on m.nd = dg.nd

--31) T m th ng tin v? nh  su?t b?n c?a quy?n s ch m  ch?a ???c ai m??n
select nxb, ngaymuon
from sach s join muon m on s.ns = m.ns
where ngaymuon is null


