create table BOOK_TYPES
(
    id        serial
        constraint book_types_pk
            primary key,
    name      varchar(50),
    cnt       integer,
    fine      integer,
    day_count integer
);

create table BOOKS
(
    id      serial
        constraint books_pk
            primary key,
    name    varchar(50),
    cnt     integer,
    type_id integer
        constraint fk_books_book_types
            references book_types
);

create table CLIENTS
(
    id             serial
        constraint clients_pk
            primary key,
    first_name     varchar(20),
    last_name      varchar(20),
    pather_name    varchar(20),
    passport_seria varchar(20),
    passport_num   varchar(20)
);

create table JOURNAL
(
    id         serial
        constraint journal_pk
            primary key,
    book_id    integer
        constraint fk_journal_books
            references books,
    clients_id integer
        constraint fk_journal_clients
            references clients,
    date_beg   timestamp(3),
    date_end   timestamp(3),
    date_ret   timestamp(3)
);

insert into BOOK_TYPES
values (5, 'Science Fiction', 50, 15, 30);

insert into BOOKS (name, cnt, type_id)
values ('1984', 7, 5);

insert into CLIENTS (first_name, last_name, pather_name, passport_seria, passport_num)
values ('Abraham',
        'Lincoln',
        'president of the US',
        '5555',
        '567890');

insert into JOURNAL (BOOK_ID, CLIENTS_ID, DATE_BEG, DATE_END, DATE_RET)
VALUES (
           11,
           5,
           '2019-06-10',
           '2019-06-22',
           '2020-06-22'
       );