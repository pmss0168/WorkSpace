--T�m s? th�ng th??ng gi?a c�c b?ng trong CSDL
SELECT
    * FROM an;
SELECT
    * FROM lui_toi;
SELECT
    * FROM nguoi_an;    
SELECT
    * FROM nguoi_an;
SELECT
    * FROM phuc_vu;
--1. Th�m kh�a ch�nh cho c�c b?ng ?� cho
--??t thu?c t�nh "ten" l� kh�a ngo�i c?a b?ng LUI_TOI v� AN
--Th�m r�ng bu?c gi�>0 cho c?t "gia" c?a b?ng PHUC_VU   
--2. Cho bi?t qu�n �Pizza Hut� ?� ph?c v? c�c b�nh pizza n�o ?
select quanpizza,pizza
from phuc_vu
where quanpizza = 'Pizza Hut';
--3. Danh s�ch c�c b�nh pizza m� c�c qu�n c� b�n ?
select quanpizza, pizza
from phuc_vu;
--4. Cho bi?t t�n c�c qu�n c� ph?c v? c�c b�nh pizza m� t�n g?m ch? �m�
select quanpizza, pizza
from phuc_vu
where pizza like '%m';
--5. T�m t�n v� tu?i c?a ng??i ?n ?� ??n qu�n �Dominos�, s?p x?p k?t qu? gi?m d?n theo
--tu?i?
select n.ten, n.tuoi
from lui_toi l JOIN nguoi_an n on n.ten = l.ten
where l.quanpizza = 'Dominos' order by n.tuoi desc;
--6. T�m t�n qu�n pizza v� s? b�nh pizza m� m?i qu�n ph?c v? ?
select quanpizza, count (*)pizza
from phuc_vu
group by quanpizza;
--7. T�m t�n nh?ng qu�n pizza ph?c v? pizza v?i gi� cao nh?t ?
select quanpizza, gia
from phuc_vu
where gia=(select max(gia)from phuc_vu);
--8. T�m t�n c�c qu�n c� ph?c v? �t nh?t m?t b�nh pizza m� �Ian� th�ch ?n ?
select a.ten,a.pizza,p.quanpizza
from an a JOIN phuc_vu p on p.pizza = a.pizza
where a.ten = 'Ian';
--9. T�m t�n c�c qu�n c� ph?c v? �t nh?t m?t b�nh m� �Eli� kh�ng th�ch ?
select distinct quanpizza
from lui_toi
where quanpizza not in (SELECT quanpizza from lui_toi where ten='Eli');
--10. T�m t�n c�c qu�n ch? ph?c v? c�c b�nh m� �Eli� th�ch ?
select a.ten,p.quanpizza,p.pizza
from an a JOIN phuc_vu p ON a.pizza= p.pizza
where a.ten='Eli';
--11. T�n qu�n c� ph?c v? b�nh v?i gi� l?n h?n t?t c? b�nh ph?c v? b?i qu�n �New York Pizza�
select gia, quanpizza
from phuc_vu
where gia > (select max (gia) from phuc_vu where quanpizza='New York Pizza');
--12. T�m t�n c�c qu�n ch? ph?c v? c�c b�nh c� gi� nh? h?n 10 ?
select quanpizza, gia
from phuc_vu
where gia < 10;
--13. T�m t�n b�nh ???c ph?c v? b?i qu�n �New York Pizza� v� qu�n �Dominos�
select pizza
from phuc_vu
where quanpizza = 'New York Pizza'
INTERSECT
    select pizza
    from phuc_vu
    where quanpizza='Dominos';
--14. T�m t�n b�nh ???c ph?c v? b?i qu�n �Little Caesars� v� kh�ng ph?c v? b?i qu�n 'PizzaHut'
select pizza
from phuc_vu
where quanpizza='Little Caesars'
minus
    select pizza
    from phuc_vu
    where quanpizza='Pizza Hut';
--15. T�m t�n c�c qu�n c� ph?c v? t?t c? c�c lo?i b�nh pizza?
--th�ch
select quanpizza
from (
    select quanpizza,
        count(pizza) as Gus
    from phuc_vu
    group by phuc_vu.quanpizza
    having count (*) >=2
);



