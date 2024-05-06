--1. Th�m kh�a ch�nh cho c�c b?ng ?� cho
alter table nguoi_an
add constraint pk_nguoian primary key (ten);
alter table lui_toi
add constraint pk_luitoi primary key (ten,quanpizza);
alter table an
add constraint pk_an primary key (ten, pizza);
alter table phuc_vu
add constraint pk_phucvu primary key (quanpizza, pizza, gia);
--??t thu?c t�nh "ten" l� kh�a ngo�i c?a b?ng LUI_TOI v� AN
alter table lui_toi
add constraint fk_luitoi foreign key (ten) references nguoi_an(ten);
alter table an
add constraint fk_an foreign key (ten) references nguoi_an(ten);
--Th�m r�ng bu?c gi�>0 cho c?t "gia" c?a b?ng PHUC_VU
alter table phuc_vu
add check (gia > 0);
--2. Cho bi?t qu�n �Pizza Hut� ?� ph?c v? c�c b�nh pizza n�o ?
select quanpizza, pizza
from phuc_vu
where quanpizza = 'Pizza Hut';
--3. Danh s�ch c�c b�nh pizza m� c�c qu�n c� b�n ?
select quanpizza, pizza
from phuc_vu;
--4. Cho bi?t t�n c�c qu�n c� ph?c v? c�c b�nh pizza m� t�n g?m ch? �m�
select distinct quanpizza
from phuc_vu
where pizza like '%m%';
--5. T�m t�n v� tu?i c?a ng??i ?n ?� ??n qu�n �Dominos�, s?p x?p k?t qu? gi?m d?n theo
--tu?i?
select n.ten, n.tuoi
from nguoi_an n join lui_toi l on n.ten = l.ten
where quanpizza = 'Dominos'
order by tuoi desc;
--6. T�m t�n qu�n pizza v� s? b�nh pizza m� m?i qu�n ph?c v? ?
select quanpizza, count(quanpizza) so_banh_ban
from phuc_vu
group by quanpizza;
--7. T�m t�n nh?ng qu�n pizza ph?c v? pizza v?i gi� cao nh?t ?
select distinct quanpizza
from phuc_vu
where gia = (select max(gia) from phuc_vu);
--8. T�m t�n c�c qu�n c� ph?c v? �t nh?t m?t b�nh pizza m� �Ian� th�ch ?n ?
select quanpizza
from phuc_vu p join an on p.pizza = an.pizza
where ten = 'Ian';
--9. T�m t�n c�c qu�n c� ph?c v? �t nh?t m?t b�nh m� �Eli� kh�ng th�ch ?
select distinct quanpizza
from phuc_vu
where pizza not in (
    select pizza
    from an
    where ten = 'Eli');
--10. T�m t�n c�c qu�n ch? ph?c v? c�c b�nh m� �Eli� th�ch ?
select distinct quanpizza
from phuc_vu
where quanpizza not in(
    select  quanpizza
    from phuc_vu
    where pizza not in (
        select pizza
        from an
        where ten = 'Eli'
        )
);
--11. T�n qu�n c� ph?c v? b�nh v?i gi� l?n h?n t?t c? b�nh ph?c v? b?i qu�n �New York
--Pizza�
select distinct quanpizza
from phuc_vu
where gia > all(select gia from phuc_vu where quanpizza = 'New York Pizza');
--12. T�m t�n c�c qu�n ch? ph?c v? c�c b�nh c� gi� nh? h?n 10 ?
select distinct quanpizza
from phuc_vu
group by quanpizza having max(gia) < 10;
--13. T�m t�n b�nh ???c ph?c v? b?i qu�n �New York Pizza� v� qu�n �Dominos�
select pizza
from phuc_vu
where quanpizza = 'New York Pizza' and pizza in (
    select pizza
    from phuc_vu
    where quanpizza = 'Dominos');
--14. T�m t�n b�nh ???c ph?c v? b?i qu�n �Little Caesars� v� kh�ng ph?c v? b?i qu�n 'Pizza
--Hut'
select pizza
from phuc_vu
where quanpizza = 'Little Caesars' and pizza not in (
    select pizza
    from phuc_vu
    where quanpizza = 'Pizza Hut');
--15. T�m t�n c�c qu�n c� ph?c v? t?t c? c�c lo?i b�nh pizza?
select quanpizza
from phuc_vu
group by quanpizza having count(pizza) = 
    (select count(*) 
    from (select distinct pizza
        from phuc_vu)); 
--16. T�n qu�n ph?c v? �t nh?t 2 b�nh pizza m� �Gus� th�ch ?
select pv.quanpizza 
from phuc_vu pv join 
    (select pizza
    from an
    where ten = 'Gus') a on pv.pizza = a.pizza
group by pv.quanpizza having count(pv.pizza) >= 2;
--17. T�m t�n c�c qu�n c� ph?c v? t?t c? c�c b�nh m� �Ian� th�ch
select pv.quanpizza
from phuc_vu pv join an a on a.pizza = pv.pizza
where a.ten = 'Ian' 
group by pv.quanpizza having count(pv.pizza) = (select count(distinct pizza) from an where ten = 'Ian');
--18. T�n ng??i ?n lui t?i �t nh?t 3 qu�n?
select ten, count(*)
from lui_toi
group by ten having count(*) >= 3;
--19. T�nh s? lo?i pizza m� m?i qu�n c� b�n ?
select quanpizza, count(*) so_banh_ban
from phuc_vu
group by quanpizza;
--20. T�m t�n ng??i ?n th�ch c�c b�nh �t nh?t l� gi?ng c�c b�nh m� Hil th�ch ?
select a.ten
from an a join (select pizza from an where ten = 'Hil') t on a.pizza = t.pizza
where ten <> 'Hil'
group by a.ten having count(distinct a.pizza) = 
    (select count(distinct pizza)
    from an
    where ten = 'Hil');
    
create table c20 as
   select pizza from an where ten='Hil';
select ten 
from an join c20 on an.pizza =c20.pizza
where ten <> 'Hil'
group by ten having count(*)= (select count(*) from c20 );
