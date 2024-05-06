CREATE TABLE khuvuc(
	IP varchar(20) NOT NULL PRIMARY KEY,
	tenKhuvuc varchar(30) not null,
	tang smallint);
----------------------------------------------------
CREATE TABLE phong(
	MP varchar(20) NOT NULL PRIMARY KEy,
	tenphong varchar(20) not null,
	somay smallint,
	IP varchar(20),
	foreign key(IP) references khuvuc(IP));
----------------------------------------------------
create table loai(
	idloai varchar(20) not null primary key,
	tenloai varchar(30) not null);
----------------------------------------------------
create table may(
	idMay varchar(20) not null primary key,
	tenmay varchar(20) not null,
	IP varchar(20),
	ad smallint check (ad BETWEEN 0 and 255),
	idloai varchar(20),
	MP varchar(20),
	foreign key(IP) references khuvuc(IP),
	foreign key(idloai) references loai(idloai));
----------------------------------------------------
create table phanmem(
	idPM varchar(20) not null primary key,
	tenPM varchar(30) not null,
	ngaymua date,
	version varchar(20),
	idloai varchar(20),
	gia smallint check(gia>=0),
	foreign key(idloai) references loai(idloai));
----------------------------------------------------
create table caidat(
	id varchar(20) not null primary key,
	idMay varchar(20),
	idPM varchar(20),
	ngaycai date default SYSDATE,
	foreign key(idMay) references may(idMay),
	foreign key(idPM) references phanmem(idPM));
	
----------------------------------------------------

insert into khuvuc values('130.120.80','Brin RDC',null);
insert into khuvuc values('130.120.81','Brin tang 1',null);
insert into khuvuc values('130.120.82','Brin tang 2',null);

----------------------------------------------------

insert into phong values('s01','salle 1',3,'130.120.80');
insert into phong values('s02','salle 2',2,'130.120.80');
insert into phong values('s03','salle 3',2,'130.120.80');
insert into phong values('s11','salle 11',2,'130.120.81');
insert into phong values('s12','salle 12',1,'130.120.81');
insert into phong values('s21','salle 21',2,'130.120.82');


--select * from khuvuc;
--select * from phong;
----------------------------------------------------

insert into loai values('TX','Terminal X-Window');
insert into loai values('UNIX','System Unix');
insert into loai values('PCNT','PC Windows NT');
insert into loai values('PCWS','PC Windows');
insert into loai values('NC','Network Computer');

-----------------------------------------------------
insert into may values('p1','Poste 1','130.120.80',01,'TX','s01');
insert into may values('p2','Poste 2','130.120.80',02,'UNIX','s01');
insert into may values('p3','Poste 3','130.120.80',03,'TX','s01');
insert into may values('p4','Poste 4','130.120.80',04,'PCWS','s02');
insert into may values('p5','Poste 5','130.120.80',05,'PCWS','s02');
insert into may values('p6','Poste 6','130.120.80',06,'UNIX','s03');
insert into may values('p7','Poste 7','130.120.80',07,'TX','s03');
insert into may values('p8','Poste 8','130.120.81',01,'UNIX','s11');
insert into may values('p9','Poste 9','130.120.81',02,'TX','s11');
insert into may values('p10','Poste 10','130.120.81',03,'UNIX','s12');
insert into may values('p11','Poste 11','130.120.82',01,'PCNT','s21');
insert into may values('p12','Poste 12','130.120.82',02,'PCWS','s21');
-----------------------------------------------------
insert into phanmem values('log1','Oracle 6','05-13-1995','6.2','UNIX',3000);
insert into phanmem values('log2','Oracle 8','09-15-1999','8i','UNIX',5600);
insert into phanmem values('log3','SQL Server','04-12-1998','7','PCNT',2700);
insert into phanmem values('log4','Front Page','06-03-1997','5','PCWS',500);
insert into phanmem values('log5','WinDev','05-12-1997','5','PCWS',750);
insert into phanmem values('log6','SQL*Net',null,'2.0','UNIX',500);
insert into phanmem values('log7','I.I.S.','04-12-2002','2','PCNT',810);

--SELECT * FROM PHANMEM;
-----------------------------------------------------
insert into caidat(idMay,idPM,id,ngaycai) values('p1','log1','13','08-10-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p1','log2','14','08-11-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p2','log1','1','05-15-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p2','log2','2','09-17-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p4','log5','3',null);
insert into caidat(idMay,idPM,id,ngaycai) values('p6','log6','4','05-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p6','log1','5','05-2-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p8','log2','6','05-19-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p8','log6','7','05-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p8','log1','12','06-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p11','log3','8','04-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p12','log4','9','04-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p11','log7','10','04-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p7','log7','11','04-01-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p12','log6','15','07-25-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p12','log1','16','03-20-2003');
insert into caidat(idMay,idPM,id,ngaycai) values('p3','log1','17','03-20-2003');


--1) V? s? ?? thông th??ng c?a các quan h?
select *
from khuvuc kv join phong p on kv.ip = p.ip
              join may m on kv.ip = m.ip
              join loai l on m.idloai = l.idloai
              join phanmem pm on l.idloai = pm.idloai
              join caidat cd on cd.idpm = pm.idpm;
--2) Lo?i c?a máy 'p8'
select tenloai
from loai l join may m on m.idloai = l.idloai
where m.idmay = 'p8';
--3) Tên c?a các ph?n m?m 'UNIX'
select tenPM, idloai
from phanmem
where idloai = 'UNIX'
--4) Tên phòng, ??a ch? IP phòng, mã phòng c?a các máy lo?i 'UNIX' ho?c 'PCWS'
select tenphong, p.ip, p.mp
from phong p join may m on p.mp = m.mp
            join loai l on l.idloai = m.idloai
where idloai = 'UNIX' or idloai = 'PCWS'
--5) Tên phòng, ??a ch? IP phòng, mã phòng c?a các máy lo?i 'UNIX' ho?c 'PCWS' ?
--khu v?c '130.120.80', s?p x?p k?t qu? t?ng d?n theo mã phòng
select tenphong, p.ip, p.mp
from phong p join may m on p.mp = m.mp
            join loai l on l.idloai = m.idloai
            join khuvuc kv on kv.ip = p.ip
where (idloai = 'UNIX' or idloai = 'PCWS') and kv.ip = '130.120.80'
order by p.mp asc
--6) S? các ph?n m?m ???c cài ??t trên máy 'p6'
select count(*) SoPMcai
from caidat
group by idmay having idmay = 'p6'
--7) S? các máy ?ã cài ph?n m?m 'log1'
select count(*) SoPMcai
from caidat
group by idpm having idpm = 'log1'
--8) Tên và ??a ch? IP (ví d?: 130.120.80.1) ??y ?? c?a các máy lo?i 'TX'
select IP || '.' || ad IPday_du
from may
where idloai = 'TX'
--9) Tính s? ph?n m?m ?ã cài ??t trên m?i máy
select idmay, count(*) SoPMcai
from caidat
group by idmay
order by SoPMcai
--10) Tính s? máy m?i phòng
select tenphong, somay
from phong
--11) Tính s? cài l?n cài ??t c?a m?i ph?n m?m trên các máy khác nhau
select idmay, count(*)
from caidat
group by idmay 
--12) Giá trung bình c?a các ph?n m?m UNIX
select round(avg(gia))
from phanmem
where idloai = 'UNIX'
--13) Ngày mua ph?n m?m g?n nh?t
select *
from phanmem
where ngaymua = (select max(ngaymua) from phanmem)
--14) S? máy có ít nh?t 2 ph?n m?m
select idmay, count(idmay) sopm
from caidat
group by idmay having count(idmay) >= 2
--15) Tìm các lo?i không thu?c lo?i máy
select idloai from loai 
minus 
select idloai from may
--16)Tìm các lo?i thu?c c? hai lo?i máy và lo?i ph?n m?m
select idloai from loai 
intersect 
select idloai from may
intersect
select idloai from phanmem
--17)Tìm các lo?i máy không ph?i là lo?i ph?n m?m
select idloai from may
minus
select idloai from phanmem
--18) ??a ch? IP ??y ?? c?a các máy cài ph?n m?m 'log6'
select IP || '.' || ad IPday_du
from may m join caidat cd on m.idmay = cd.idmay
where idpm = 'log6'
--19) ??a ch? IP ??y ?? c?a các máy cài ph?n m?m tên 'Oracle 8'
select ip || '.' || ad ip_day_du
from may m join caidat cd on m.idmay = cd.idmay
          join phanmem pm on pm.idpm = cd.idpm
where pm.tenpm = 'Oracle 8'
--20) Tên c?a các khu v?c có chính xác 3 máy lo?i 'TX'
select kv.tenkhuvuc
from khuvuc kv join may m on m.ip = kv.ip
where m.idloai = 'TX'
group by kv.tenkhuvuc having count(*) >= 3
--21) Tên phòng có ít nh?t m?t máy cài ph?n m?m tên 'Oracle 6'
select tenphong
from phong p join may m on m.mp = p.mp
            join caidat cd on m.idmay = cd.idmay
            join phanmem pm on pm.idpm = cd.idpm
where pm.tenpm = 'Oracle 6'
group by tenphong having count(*) >= 1
--22) Tên ph?n m?m ???c mua g?n nh?t
select tenpm
from phanmem 
where ngaymua = (select max(ngaymua) from phanmem)
--23) Tên c?a ph?n m?m PCNT có giá l?n h?n b?t k? giá c?a m?t ph?n m?m UNIX
--nào
select tenpm
from phanmem
where idloai = 'PCNT' and gia > Any (select gia
                                from phanmem
                                where idloai = 'UNIX')
--24) Tên c?a ph?n m?m UNIX có giá l?n h?n t?t c? các giá c?a các ph?n m?m PCNT
--C1
select tenpm
from phanmem
where idloai = 'UNIX' and gia > Any (select gia
                                from phanmem
                                where idloai = 'PCNT')
--C2
select tenpm
from phanmem
where idloai = 'UNIX' and gia > (select min(gia)
                                from phanmem
                                where idloai = 'PCNT');
--25) Tên c?a máy có ít nh?t m?t ph?n m?m chung v?i máy 'p6'
select distinct tenmay
from may m join caidat cd on m.idmay = cd.idmay
where m.idmay <> 'p6' and cd.idpm in 
                                (select idpm from caidat 
                                where idmay = 'p6');
--26) Tên c?a các máy có cùng ph?n m?m nh? máy 'p6' (có th? nhi?u ph?n m?m h?n
--máy 'p6')
create table c26 as
  select idpm from caidat where idmay = 'p6';

select distinct tenmay
from caidat cd join c26 on cd.idpm = c26.idpm
            join may m on m.idmay = cd.idmay
where cd.idmay <> 'p6'
group by tenmay having count(*)  = (select count(*) from c26);
drop table c26;
--27) Tên c?a các máy có chính xác các ph?n m?m nh? máy 'p2'
CREATE TABLE c27 AS -- Tim idmay co cai phan mem giong may p2 nhu cau 26
SELECT idmay
FROM caidat c
JOIN
  (SELECT idpm FROM caidat WHERE idmay='p2'
  ) p
ON c.idpm   =p.idpm
WHERE idmay<>'p2'
GROUP BY idmay
HAVING COUNT(*) =
  (SELECT COUNT(*) FROM caidat WHERE idmay='p2'
  )
SELECT idmay -- tim idmay co chinh xac phan mem nhu p2
FROM c27
WHERE idmay IN
  (SELECT idmay
  FROM caidat
  GROUP BY idmay
  HAVING COUNT(*) =
    (SELECT COUNT(*) FROM caidat WHERE idmay='p2'
    )
  )
DROP TABLE c27;
--GIAI

-- 8 VÃ­ dá»¥ IP day du
select IP || '.' || ad IPday_du
from may

-- 25
select * from caidat order by idmay;
select idmay
from caidat 
where idmay<>'p6' and idpm IN 
    (select idpm from caidat where idmay='p6')
-- 26 


CREATE TABLE c26 AS   -- Phan mem cai tren may p6
   select idpm from caidat where idmay='p6';

select idmay
from caidat c join c26 p on c.idpm=p.idpm
where idmay<>'p6'
group by idmay having count(*) = (select count(*) from c26)
drop table c26

-- 27
 create table c27 as -- Tim idmay co cai phan mem giong may p2 nhu cau 26 
    select idmay
    from caidat c join (select idpm from caidat where idmay='p2') p on c.idpm=p.idpm
    where idmay<>'p2'
    group by idmay having count(*) = (select count(*) from caidat where idmay='p2')
	
select idmay  -- tim idmay co chinh xac phan mem nhu p2
from c27
where idmay in ( select idmay
                 from caidat 
                group by idmay having count(*) = (select count(*) from caidat where idmay='p2'))
drop table c27;

-- CÃ¢u 27i : May chi cai phan mem nhÆ° mÃ¡y P2
select idmay
from caidat
where idmay <>'p2' and idmay NOT IN 
        (select idmay
        from caidat
        where idpm NOT IN 
            (select idpm
            from caidat
            where idmay='p2'));
