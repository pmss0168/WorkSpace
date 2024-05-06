--1. Thêm khóa chính cho các b?ng ?ã cho
alter table nguoi_an
add constraint pk_nguoian primary key (ten);
alter table lui_toi
add constraint pk_luitoi primary key (ten,quanpizza);
alter table an
add constraint pk_an primary key (ten, pizza);
alter table phuc_vu
add constraint pk_phucvu primary key (quanpizza, pizza, gia);
--??t thu?c tính "ten" là khóa ngoài c?a b?ng LUI_TOI và AN
alter table lui_toi
add constraint fk_luitoi foreign key (ten) references nguoi_an(ten);
alter table an
add constraint fk_an foreign key (ten) references nguoi_an(ten);
--Thêm ràng bu?c giá>0 cho c?t "gia" c?a b?ng PHUC_VU
alter table phuc_vu
add check (gia > 0);
--2. Cho bi?t quán ‘Pizza Hut’ ?ã ph?c v? các bánh pizza nào ?
select quanpizza, pizza
from phuc_vu
where quanpizza = 'Pizza Hut';
--3. Danh sách các bánh pizza mà các quán có bán ?
select quanpizza, pizza
from phuc_vu;
--4. Cho bi?t tên các quán có ph?c v? các bánh pizza mà tên g?m ch? ‘m’
select distinct quanpizza
from phuc_vu
where pizza like '%m%';
--5. Tìm tên và tu?i c?a ng??i ?n ?ã ??n quán ‘Dominos’, s?p x?p k?t qu? gi?m d?n theo
--tu?i?
select n.ten, n.tuoi
from nguoi_an n join lui_toi l on n.ten = l.ten
where quanpizza = 'Dominos'
order by tuoi desc;
--6. Tìm tên quán pizza và s? bánh pizza mà m?i quán ph?c v? ?
select quanpizza, count(quanpizza) so_banh_ban
from phuc_vu
group by quanpizza;
--7. Tìm tên nh?ng quán pizza ph?c v? pizza v?i giá cao nh?t ?
select distinct quanpizza
from phuc_vu
where gia = (select max(gia) from phuc_vu);
--8. Tìm tên các quán có ph?c v? ít nh?t m?t bánh pizza mà “Ian” thích ?n ?
select quanpizza
from phuc_vu p join an on p.pizza = an.pizza
where ten = 'Ian';
--9. Tìm tên các quán có ph?c v? ít nh?t m?t bánh mà “Eli” không thích ?
select distinct quanpizza
from phuc_vu
where pizza not in (
    select pizza
    from an
    where ten = 'Eli');
--10. Tìm tên các quán ch? ph?c v? các bánh mà “Eli” thích ?
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
--11. Tên quán có ph?c v? bánh v?i giá l?n h?n t?t c? bánh ph?c v? b?i quán ‘New York
--Pizza’
select distinct quanpizza
from phuc_vu
where gia > all(select gia from phuc_vu where quanpizza = 'New York Pizza');
--12. Tìm tên các quán ch? ph?c v? các bánh có giá nh? h?n 10 ?
select distinct quanpizza
from phuc_vu
group by quanpizza having max(gia) < 10;
--13. Tìm tên bánh ???c ph?c v? b?i quán ‘New York Pizza’ và quán ‘Dominos’
select pizza
from phuc_vu
where quanpizza = 'New York Pizza' and pizza in (
    select pizza
    from phuc_vu
    where quanpizza = 'Dominos');
--14. Tìm tên bánh ???c ph?c v? b?i quán ‘Little Caesars’ và không ph?c v? b?i quán 'Pizza
--Hut'
select pizza
from phuc_vu
where quanpizza = 'Little Caesars' and pizza not in (
    select pizza
    from phuc_vu
    where quanpizza = 'Pizza Hut');
--15. Tìm tên các quán có ph?c v? t?t c? các lo?i bánh pizza?
select quanpizza
from phuc_vu
group by quanpizza having count(pizza) = 
    (select count(*) 
    from (select distinct pizza
        from phuc_vu)); 
--16. Tên quán ph?c v? ít nh?t 2 bánh pizza mà ‘Gus’ thích ?
select pv.quanpizza 
from phuc_vu pv join 
    (select pizza
    from an
    where ten = 'Gus') a on pv.pizza = a.pizza
group by pv.quanpizza having count(pv.pizza) >= 2;
--17. Tìm tên các quán có ph?c v? t?t c? các bánh mà ‘Ian’ thích
select pv.quanpizza
from phuc_vu pv join an a on a.pizza = pv.pizza
where a.ten = 'Ian' 
group by pv.quanpizza having count(pv.pizza) = (select count(distinct pizza) from an where ten = 'Ian');
--18. Tên ng??i ?n lui t?i ít nh?t 3 quán?
select ten, count(*)
from lui_toi
group by ten having count(*) >= 3;
--19. Tính s? lo?i pizza mà m?i quán có bán ?
select quanpizza, count(*) so_banh_ban
from phuc_vu
group by quanpizza;
--20. Tìm tên ng??i ?n thích các bánh ít nh?t là gi?ng các bánh mà Hil thích ?
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
