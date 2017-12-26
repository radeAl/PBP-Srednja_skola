

-- -----------------------------------------------------
-- Schema Srednja_skola
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `Srednja_skola` ;

-- -----------------------------------------------------
-- Schema Srednja_skola
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `Srednja_skola` DEFAULT CHARACTER SET utf8 ;
USE `Srednja_skola` ;

-- -----------------------------------------------------
-- Table Nastavnik
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Nastavnik` ;

create table if not exists Nastavnik(
	id int not null,
	ime varchar(45) not null,
	prezime varchar(45) not null,
	zvanje varchar(45) not null,
	PRIMARY KEY(id)
);

-- -----------------------------------------------------
-- Table Predmet
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Predmet` ;

create table if not exists Predmet(
	id int not null,
	naziv varchar(45),
	opis text,
	PRIMARY KEY(id)
);

-- -----------------------------------------------------
-- Table Smer
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Smer` ;

create table if not exists Smer(
	id int not null,
	naziv varchar(45) not null,
	opis text not null,
	zvanje varchar(45),
	PRIMARY KEY(id)
);

-- -----------------------------------------------------
-- Table Staratelj
-- -----------------------------------------------------

DROP TABLE IF EXISTS `Staratelj` ;

create table if not exists Staratelj(
	id int not null,
	ime varchar(45) not null,
	prezime varchar(45) not null,
	telefon varchar(15),

	PRIMARY KEY(id)
);

-- -----------------------------------------------------
-- Table Status
-- -----------------------------------------------------

DROP TABLE IF EXISTS `Status` ;

create table if not exists Status(
	id int not null auto_increment,
	naziv varchar(45) not null,
	opis text,
	PRIMARY KEY(id)
);

-- -----------------------------------------------------
-- Table Odeljenje
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Odeljenje` ;

create table if not exists Odeljenje(
	id int not null,
	naziv varchar(45) not null,
	godina smallint not null,
	id_razrednog int not null,
	id_smera int not null,
	PRIMARY KEY(id),
	FOREIGN KEY(id_razrednog) references Nastavnik(id),
	FOREIGN KEY(id_smera) references Smer(id)
	
);

-- -----------------------------------------------------
-- Table Ucenik
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Ucenik` ;

create table if not exists Ucenik(
	id int not null,
	ime varchar(45) not null,
	prezime varchar(45) not null,
	mesto_rodjenja varchar(45) not null,
	datum_rodjenja date not null,
	adresa varchar(45),
	prosek float not null default 0.0,
	id_status int not null,
	id_odeljenja int not null,
	PRIMARY KEY(id),

	
	FOREIGN KEY(id_status) references 	Status(`id`)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION,
	
	
	FOREIGN KEY(id_odeljenja) references Odeljenje(`id`	)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION

);



-- -----------------------------------------------------
-- Table Izostanci
-- -----------------------------------------------------

DROP TABLE IF EXISTS `Izostanci` ;

create table if not exists Izostanci(
	id_ucenika int not null auto_increment,
	datum date not null,
	broj_casova smallint not null,
	opravdano bool,
	PRIMARY KEY(id_ucenika, datum),
	FOREIGN KEY(id_ucenika) references Ucenik(id)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION
);









-- -----------------------------------------------------
-- Table Ucenik-Staratelj
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Ucenik_Staratelj` ;

create table if not exists Ucenik_Staratelj(
	id_ucenika int not null,
	id_staratelja int not null,
	PRIMARY KEY(id_ucenika, id_staratelja),
	
	FOREIGN KEY(id_ucenika) references Ucenik(id)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION,
	FOREIGN KEY(id_staratelja) references Staratelj(id)
	-- ON DELETE NO ACTION
    -- ON UPDATE NO ACTION

);



-- -----------------------------------------------------
-- Table Predaje
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Predaje` ;

create table if not exists Predaje(
	id_nastavnika int not null,
	id_predmeta int not null,
	id_odeljenja int not null,
	PRIMARY KEY(id_nastavnika, id_predmeta, id_odeljenja),
	FOREIGN KEY(id_nastavnika) references Nastavnik(id),
	FOREIGN KEY(id_predmeta) references Predmet(id),
	FOREIGN KEY(id_odeljenja) references Odeljenje(id)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION
	
);



-- -----------------------------------------------------
-- Table Ocena
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Ocena` ;

create table if not exists Ocena(
	id_ucenika int not null,
	id_predmeta int not null,
	datum date not null,
	ocena int,
	
	PRIMARY KEY(id_predmeta, id_ucenika, datum),
	
	
	FOREIGN KEY(id_predmeta) references Predmet(id),
	FOREIGN KEY(id_ucenika) references Ucenik(id)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION
	
	
);

-- -----------------------------------------------------
-- Table Zakljucna
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Zaklucna` ;

create table if not exists Zakljucna(
	id_ucenika int not null,
	id_predmeta int not null,
	ocena int,
	
	PRIMARY KEY(id_predmeta, id_ucenika),
	
	FOREIGN KEY(id_predmeta) references Predmet(id),
	
	FOREIGN KEY(id_ucenika) references Ucenik(id)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION
	
	
);

-- -----------------------------------------------------
-- Table Smer-Predmet
-- -----------------------------------------------------

DROP TABLE IF EXISTS `Smer_Predmet` ;

create table if not exists Smer_Predmet(
	id_smera int not null,
	id_predmeta int not null,
	godina smallint not null,
	PRIMARY KEY (id_smera, id_predmeta),
	FOREIGN KEY (id_smera) references Smer(id),
	FOREIGN KEY (id_predmeta) references Predmet(id)
);



