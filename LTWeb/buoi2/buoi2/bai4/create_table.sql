CREATE TABLE BOOKSTORE.BOOKS(
    book_id int auto_increment primary key,
    title varchar(200) not null collate 'utf8_general_ci',
    introduction varchar(1000) collate 'utf8_bin'
);
CREATE TABLE BOOKSTORE.IMAGES(
    image_id int auto_increment primary key,
    book_id int,
    file_name varchar(200) not null,
    mine_type varchar(50) not null,
    file_size int not null,
    image_data mediumblob not null,
    foreign key (book_id) references bookstore.books(book_id) on delete cascade
);