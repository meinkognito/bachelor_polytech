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
select client0_.id                 as id1_2_0_,
       client0_.first_name         as first_na2_2_0_,
       client0_.journal_client_id  as journal_7_2_0_,
       client0_.last_name          as last_nam3_2_0_,
       client0_.passport_num       as passport4_2_0_,
       client0_.passport_seria     as passport5_2_0_,
       client0_.pather_name        as pather_n6_2_0_,
       journal1_.id                as id1_3_1_,
       journal1_.date_beg          as date_beg2_3_1_,
       journal1_.date_end          as date_end3_3_1_,
       journal1_.date_ret          as date_ret4_3_1_,
       books2_.book_id             as book_id6_1_2_,
       books2_.id                  as id1_1_2_,
       books2_.id                  as id1_1_3_,
       books2_.cnt                 as cnt2_1_3_,
       books2_.journal_book_id     as journal_4_1_3_,
       books2_.name                as name3_1_3_,
       books2_.type_id             as type_id5_1_3_,
       journal3_.id                as id1_3_4_,
       journal3_.date_beg          as date_beg2_3_4_,
       journal3_.date_end          as date_end3_3_4_,
       journal3_.date_ret          as date_ret4_3_4_,
       clients4_.client_id         as client_i8_2_5_,
       clients4_.id                as id1_2_5_,
       clients4_.id                as id1_2_6_,
       clients4_.first_name        as first_na2_2_6_,
       clients4_.journal_client_id as journal_7_2_6_,
       clients4_.last_name         as last_nam3_2_6_,
       clients4_.passport_num      as passport4_2_6_,
       clients4_.passport_seria    as passport5_2_6_,
       clients4_.pather_name       as pather_n6_2_6_,
       booktype5_.id               as id1_0_7_,
       booktype5_.cnt              as cnt2_0_7_,
       booktype5_.day_count        as day_coun3_0_7_,
       booktype5_.fine             as fine4_0_7_,
       booktype5_.name             as name5_0_7_
from clients client0_
         left outer join
     journal journal1_ on client0_.journal_client_id = journal1_.id
         left outer join
     books books2_ on journal1_.id = books2_.book_id
         left outer join
     journal journal3_ on books2_.journal_book_id = journal3_.id
         left outer join
     clients clients4_ on journal3_.id = clients4_.client_id
         left outer join
     book_types booktype5_ on books2_.type_id = booktype5_.id
where client0_.id=?

-- Hibernate:
select booktype0_.id               as id1_0_0_,
       booktype0_.cnt              as cnt2_0_0_,
       booktype0_.day_count        as day_coun3_0_0_,
       booktype0_.fine             as fine4_0_0_,
       booktype0_.name             as name5_0_0_,
       books1_.type_id             as type_id5_1_1_,
       books1_.id                  as id1_1_1_,
       books1_.id                  as id1_1_2_,
       books1_.cnt                 as cnt2_1_2_,
       books1_.journal_book_id     as journal_4_1_2_,
       books1_.name                as name3_1_2_,
       books1_.type_id             as type_id5_1_2_,
       journal2_.id                as id1_3_3_,
       journal2_.date_beg          as date_beg2_3_3_,
       journal2_.date_end          as date_end3_3_3_,
       journal2_.date_ret          as date_ret4_3_3_,
       books3_.book_id             as book_id6_1_4_,
       books3_.id                  as id1_1_4_,
       books3_.id                  as id1_1_5_,
       books3_.cnt                 as cnt2_1_5_,
       books3_.journal_book_id     as journal_4_1_5_,
       books3_.name                as name3_1_5_,
       books3_.type_id             as type_id5_1_5_,
       clients4_.client_id         as client_i8_2_6_,
       clients4_.id                as id1_2_6_,
       clients4_.id                as id1_2_7_,
       clients4_.first_name        as first_na2_2_7_,
       clients4_.journal_client_id as journal_7_2_7_,
       clients4_.last_name         as last_nam3_2_7_,
       clients4_.passport_num      as passport4_2_7_,
       clients4_.passport_seria    as passport5_2_7_,
       clients4_.pather_name       as pather_n6_2_7_,
       journal5_.id                as id1_3_8_,
       journal5_.date_beg          as date_beg2_3_8_,
       journal5_.date_end          as date_end3_3_8_,
       journal5_.date_ret          as date_ret4_3_8_
from book_types booktype0_
         left outer join
     books books1_ on booktype0_.id = books1_.type_id
         left outer join
     journal journal2_ on books1_.journal_book_id = journal2_.id
         left outer join
     books books3_ on journal2_.id = books3_.book_id
         left outer join
     clients clients4_ on journal2_.id = clients4_.client_id
         left outer join
     journal journal5_ on clients4_.journal_client_id = journal5_.id
where booktype0_.id=?

-- Hibernate:
select book0_.id                   as id1_1_0_,
       book0_.cnt                  as cnt2_1_0_,
       book0_.journal_book_id      as journal_4_1_0_,
       book0_.name                 as name3_1_0_,
       book0_.type_id              as type_id5_1_0_,
       journal1_.id                as id1_3_1_,
       journal1_.date_beg          as date_beg2_3_1_,
       journal1_.date_end          as date_end3_3_1_,
       journal1_.date_ret          as date_ret4_3_1_,
       books2_.book_id             as book_id6_1_2_,
       books2_.id                  as id1_1_2_,
       books2_.id                  as id1_1_3_,
       books2_.cnt                 as cnt2_1_3_,
       books2_.journal_book_id     as journal_4_1_3_,
       books2_.name                as name3_1_3_,
       books2_.type_id             as type_id5_1_3_,
       booktype3_.id               as id1_0_4_,
       booktype3_.cnt              as cnt2_0_4_,
       booktype3_.day_count        as day_coun3_0_4_,
       booktype3_.fine             as fine4_0_4_,
       booktype3_.name             as name5_0_4_,
       clients4_.client_id         as client_i8_2_5_,
       clients4_.id                as id1_2_5_,
       clients4_.id                as id1_2_6_,
       clients4_.first_name        as first_na2_2_6_,
       clients4_.journal_client_id as journal_7_2_6_,
       clients4_.last_name         as last_nam3_2_6_,
       clients4_.passport_num      as passport4_2_6_,
       clients4_.passport_seria    as passport5_2_6_,
       clients4_.pather_name       as pather_n6_2_6_,
       journal5_.id                as id1_3_7_,
       journal5_.date_beg          as date_beg2_3_7_,
       journal5_.date_end          as date_end3_3_7_,
       journal5_.date_ret          as date_ret4_3_7_
from books book0_
         left outer join
     journal journal1_ on book0_.journal_book_id = journal1_.id
         left outer join
     books books2_ on journal1_.id = books2_.book_id
         left outer join
     book_types booktype3_ on books2_.type_id = booktype3_.id
         left outer join
     clients clients4_ on journal1_.id = clients4_.client_id
         left outer join
     journal journal5_ on clients4_.journal_client_id = journal5_.id
where book0_.id=?
