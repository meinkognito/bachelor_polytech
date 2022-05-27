-- Hibernate:
insert
into book_types
    (cnt, day_count, fine, name)
values (?, ?, ?, ?)

-- Hibernate:
insert
into books
    (cnt, name, type_id)
values (?, ?, ?)

-- Hibernate:
insert
into clients
(first_name, last_name, passport_num, passport_seria, pather_name)
values (?, ?, ?, ?, ?)

-- Hibernate:
insert
into journal
    (date_beg, date_end, date_ret)
values (?, ?, ?)

-- Hibernate:
update
    books
set book_id=?
where id =?

-- Hibernate:
update
    clients
set client_id=?
where id =?

-- Hibernate:
select booktype0_.id        as id1_0_0_,
       booktype0_.cnt       as cnt2_0_0_,
       booktype0_.day_count as day_coun3_0_0_,
       booktype0_.fine      as fine4_0_0_,
       booktype0_.name      as name5_0_0_,
       books1_.type_id      as type_id4_1_1_,
       books1_.id           as id1_1_1_,
       books1_.id           as id1_1_2_,
       books1_.cnt          as cnt2_1_2_,
       books1_.name         as name3_1_2_,
       books1_.type_id      as type_id4_1_2_
from book_types booktype0_
         left outer join
     books books1_ on booktype0_.id = books1_.type_id
where booktype0_.id=?

-- Hibernate:
select book0_.id            as id1_1_0_,
       book0_.cnt           as cnt2_1_0_,
       book0_.name          as name3_1_0_,
       book0_.type_id       as type_id4_1_0_,
       booktype1_.id        as id1_0_1_,
       booktype1_.cnt       as cnt2_0_1_,
       booktype1_.day_count as day_coun3_0_1_,
       booktype1_.fine      as fine4_0_1_,
       booktype1_.name      as name5_0_1_
from books book0_
         left outer join
     book_types booktype1_ on book0_.type_id = booktype1_.id
where book0_.id=?

-- Hibernate:
select books0_.type_id as type_id4_1_0_,
       books0_.id      as id1_1_0_,
       books0_.id      as id1_1_1_,
       books0_.cnt     as cnt2_1_1_,
       books0_.name    as name3_1_1_,
       books0_.type_id as type_id4_1_1_
from books books0_
where books0_.type_id =?

-- Hibernate:
select booktype0_.id        as id1_0_0_,
       booktype0_.cnt       as cnt2_0_0_,
       booktype0_.day_count as day_coun3_0_0_,
       booktype0_.fine      as fine4_0_0_,
       booktype0_.name      as name5_0_0_,
       books1_.type_id      as type_id4_1_1_,
       books1_.id           as id1_1_1_,
       books1_.id           as id1_1_2_,
       books1_.cnt          as cnt2_1_2_,
       books1_.name         as name3_1_2_,
       books1_.type_id      as type_id4_1_2_
from book_types booktype0_
         left outer join
     books books1_ on booktype0_.id = books1_.type_id
where booktype0_.id =?

-- Hibernate:
delete from
    books
where
    id=?

-- Hibernate:
delete
from book_types
where id=?
-- Hibernate:
select client0_.id             as id1_2_0_,
       client0_.first_name     as first_na2_2_0_,
       client0_.last_name      as last_nam3_2_0_,
       client0_.passport_num   as passport4_2_0_,
       client0_.passport_seria as passport5_2_0_,
       client0_.pather_name    as pather_n6_2_0_
from clients client0_
where client0_.id =?

-- Hibernate:
update
    clients
set
    first_name = ?,
        last_name=?,
        passport_num=?,
        passport_seria=?,
        pather_name=? 
    where
        id=?

-- Hibernate:
select journal0_.id             as id1_3_0_,
       journal0_.date_beg       as date_beg2_3_0_,
       journal0_.date_end       as date_end3_3_0_,
       journal0_.date_ret       as date_ret4_3_0_,
       books1_.book_id          as book_id5_1_1_,
       books1_.id               as id1_1_1_,
       books1_.id               as id1_1_2_,
       books1_.cnt              as cnt2_1_2_,
       books1_.name             as name3_1_2_,
       books1_.type_id          as type_id4_1_2_,
       booktype2_.id            as id1_0_3_,
       booktype2_.cnt           as cnt2_0_3_,
       booktype2_.day_count     as day_coun3_0_3_,
       booktype2_.fine          as fine4_0_3_,
       booktype2_.name          as name5_0_3_,
       clients3_.client_id      as client_i7_2_4_,
       clients3_.id             as id1_2_4_,
       clients3_.id             as id1_2_5_,
       clients3_.first_name     as first_na2_2_5_,
       clients3_.last_name      as last_nam3_2_5_,
       clients3_.passport_num   as passport4_2_5_,
       clients3_.passport_seria as passport5_2_5_,
       clients3_.pather_name    as pather_n6_2_5_
from journal journal0_
         left outer join
     books books1_ on journal0_.id = books1_.book_id
         left outer join
     book_types booktype2_ on books1_.type_id = booktype2_.id
         left outer join
     clients clients3_ on journal0_.id = clients3_.client_id
where journal0_.id=?


-- Hibernate:
select books0_.type_id as type_id4_1_0_,
       books0_.id      as id1_1_0_,
       books0_.id      as id1_1_1_,
       books0_.cnt     as cnt2_1_1_,
       books0_.name    as name3_1_1_,
       books0_.type_id as type_id4_1_1_
from books books0_
where books0_.type_id =?


-- Hibernate:
update
    books
set
    book_id = null where
        book_id=?

-- Hibernate:
update
    clients
set client_id=null
where client_id =?

-- Hibernate:
delete from
    journal
where
    id=?

-- Hibernate:
select book0_.id            as id1_1_0_,
       book0_.cnt           as cnt2_1_0_,
       book0_.name          as name3_1_0_,
       book0_.type_id       as type_id4_1_0_,
       booktype1_.id        as id1_0_1_,
       booktype1_.cnt       as cnt2_0_1_,
       booktype1_.day_count as day_coun3_0_1_,
       booktype1_.fine      as fine4_0_1_,
       booktype1_.name      as name5_0_1_
from books book0_
         left outer join
     book_types booktype1_ on book0_.type_id = booktype1_.id
where book0_.id=?

-- Hibernate:
select books0_.type_id as type_id4_1_0_,
       books0_.id      as id1_1_0_,
       books0_.id      as id1_1_1_,
       books0_.cnt     as cnt2_1_1_,
       books0_.name    as name3_1_1_,
       books0_.type_id as type_id4_1_1_
from books books0_
where books0_.type_id=?
