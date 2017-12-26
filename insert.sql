use Srednja_skola;
insert into Nastavnik values
	(1, 'Rade', 'Petrovic', 'Profesor Matematike i Informatika'),
	(2, 'Jovan', 'Markovic', 'Profesor Srpskog jezika'),
	(3, 'Milan', 'Jovanovic', 'Psiholog'),
	(4, 'Rajko', 'Ivanovic', 'Profesor Fizickog'),
	(5, 'Milan', 'Milanovic', 'Profesor Matematike'),
	(6, 'Slavica', 'Grkavac', 'Profesor Engleskog jezika'),
	(7, 'Dusko', 'Pekovic', 'Profesor Matematike'),
	(8, 'Milan', 'Mladenovic', 'Diplomirani Politikolog'),
	(9, 'Jovana', 'Ilic', 'Istoricarka'),
	(10, 'Marija', 'Andric', 'Fizicarka'),
	(11, 'Svetlana', 'Bojkovic', 'Biolog'),
	(12, 'Nenad', 'Boskovic', 'Profesor Istorije i Geografije'),
	(13, 'Vesna', 'Boskovic', 'Profesor Biologije'),
	(14, 'Milorad', 'Lambeta', 'Akademski Slikar'),
	(15, 'Ivana', 'Petrovic', 'Profesor Srpskog jezika'),
	(16, 'Isidora', 'Petricevic', 'Profesor Francuskog jezika'),
	(17, 'Milena', 'Davidovic', 'Profesor Latinskog'),
	(18, 'Rajko', 'Milentijevic', 'Profesor Fizike i Astronomije'),
	(19, 'Starina', 'Novak', 'Profesor Istorije'),
	(20, 'Strahinja', 'Simovic', 'Profesor Muzickog'),
	(21, 'Natalija', 'Rodic', 'Profesor Hemije'),
	(22, 'Rade', 'Petrovic', 'Profesor Nemackog'),
	(23, 'Helena', 'Djuric', 'Profesor Matematike'),
	(24, 'Dragana', 'Kostic', 'Profesor'),
	(25, 'Rastimir', 'Mihic', 'Profesor umetnosti');

insert into Predmet values
	(1456, 'Matematika 1', 'Skupovi , algebarksi izrazi'),
	(2, 'Matematika 2', 'Kvadratna jednacina, Jednacine viseg reda , Kvadratne nejednacine, funkcije'),
	(3, 'Matematika 3', ' logaritmi, trigonometriske  funkcije, nizov, limesi'),
	(4, 'Matematika 4', 'izvodi, integrali'),
	(4444, 'Matematika izborni', 'izvodi, integrali'),
	(5, 'Srpski jezik 1', 'Padezi Glasovne promene - anticka knjizevnost'),
	(6, 'Srpski jezik 2', 'Padezi Glasovne promene - anticka knjizevnost'),
	(7, 'Srpski jezik 3', 'Padezi Glasovne promene - anticka knjizevnost'),
	(811, 'Srpski jezik 4', 'Padezi Glasovne promene - anticka knjizevnost'),
	(8, 'Srpski jezik izorni', 'Padezi Glasovne promene - anticka knjizevnost'),
	(9, 'Engleski jezik 1', 'Sadasnje vreme'),
	(10, 'Engleski jezik 2', 'Sadasnje vreme'),
	(11, 'Engleski jezik 3', 'Sadasnje vreme'),
	(12, 'Engleski jezik 4', 'Sadasnje vreme'),
	(13, 'Francuski jezik 1', 'Uvod'),
	(14, 'Francuski jezik 2', 'Uvod'),
	(15, 'Francuski jezik 3', 'Uvod'),
	(16, 'Francuski jezik 4', 'Uvod'),
	(17, 'Psihologija 1', 'Uvod'),
	(18, 'Psihologija 2', 'Uvod'),
	(19, 'Psihologija 3', 'Uvod'),
	(20, 'Psihologija 4', 'Uvod'),
	(21, 'Fizicko 1', 'Trcanje'),
	(22, 'Fizicko 2', 'Trcanje'),
	(23, 'Fizicko 3', 'Trcanje'),
	(24, 'Fizicko 4', 'Trcanje'),
	(25, 'Informatika 1', 'Koriscenje racunara'),
	(26, 'Informatika 2', 'Koriscenje racunara'),
	(27, 'Informatika 3', 'Koriscenje racunara'),
	(28, 'Informatika 4', 'Koriscenje racunara'),
	(29, 'UStav', 'Osnovno'),
	(30, 'Istoria 1', 'Kameno doba'),
	(31, 'Istoria 2', 'Nemanjici'),
	(32, 'Istoria 3', 'Turci'),
	(33, 'Istoria 4', 'Veliki ratovi'),
	(34, 'Geografija 1', 'Evropa'),
	(35, 'Geografija 2', 'Amerike'),
	(36, 'Geografija 3', 'Azija i australija i afrika'),
	(37, 'Geografija 4', 'Srbija i region'),
	(38, 'Likovno 1', 'Crtanje mrtve prirode'),
	(39, 'Likovno 2', 'Crtanje  prirode'),
	(40, 'Likovno 3', 'Crtanje portreta'),
	(41, 'Muzicko 1', 'Klasicna muzika'),
	(411, 'Muzicko 2', 'Instrumenti muzika'),
	(42, 'Muzicko 3', 'Srpska muzika'),
	(43, 'Fizika 1', 'Statika'),
	(44, 'Fizika 2', 'Dinamika'),
	(45, 'Fizika 3', 'Kinematika'),
	(46, 'Fizika 4', 'El Energija'),
	(47, 'Biologija 1', 'osnove'),
	(48, 'Biologija 2', 'flora '),
	(49, 'Biologija 3', 'fauna'),
	(50, 'Biologija 4', 'anatomija'),
	(51, 'Hemija 1', 'Osnove'),
	(52, 'Hemija 2', 'KIseline'),
	(53, 'Hemija 3', 'Baze'),
	(54, 'Hemija 4', 'Organska hemija');

insert into Smer values	
	(1, 'Drustveni', 'Vecinski se izucavaju drustvene nauke', NULL),
	(2, 'Jezicki', 'Vecinsk se izucavaju jezic', NULL),
	(3, 'Prirodni', 'Vecinski se izucavaju prirodne nauke', NULL),
	(4, 'Matematicki', 'Vecinski se izucava matematika i informatika', NULL);

insert into Status values
	(1, 'Aktivan', NULL),
	(2, 'Zavrisio', NULL),
	(3, 'Izbacen', NULL),
	(4, 'Ispisao se', NULL);

insert into Odeljenje values
	(1, 'Matematicari 1', 4, 3, 4),
	(2, 'Prirodnjaci 1', 3, 10, 3),
	(3, 'Drustvenjaci 1', 2, 4, 1),
	(4, 'jezicari', 0 ,15 ,2 ),
	(5, 'Prirodnjaci 2', 1,11 , 3);

insert into Ucenik values
	(1, 'Ranko', 'Zeravica', 'Beograd', '1999-12-12', 'Carigradska 5', 0.00,1, 1),
	(2, 'Milena', 'Kuburovic', 'Beograd', '1999-12-18', 'Vidovdanska bb',0.00, 1, 1),
	(3, 'Milan', 'Mladenovic', 'Beograd', '1999-5-12', 'Mladenovacka 2',0.00, 1, 1),
	(4, 'Petar', 'Petrovic', 'Beograd', '1999-7-13', 'Tosin bunar 2',0.00, 1, 1),
	(5, 'Milos', 'Markovic', 'Mladenovac', '1999-1-22', 'Trebinjska 1',0, 3, 1),
	(6, 'Rade', 'Markovic', 'Kraljevo', '2000-1-22', 'Bilecka 1',0, 1, 1),
	(7, 'Nikola', 'Jovanovic', 'Beograd', '1998-10-2', 'Kneza Milosa 32',0, 4, 1),

	(8, 'KAtarina', 'Jovanovic', 'Beograd', '2000-12-12', 'Kneza Milosa 32',0, 1, 2),
	(9, 'Milica', 'Milosevic', 'Beograd', '2000-12-18', 'Hajduk Stanka bb',0, 1, 2),
	(10, 'Milan', 'Andric', 'Beograd', '2000-5-12', 'Petrovacka 2',0, 1, 2),
	(11, 'Jovica', 'Petrovic', 'Beograd', '2000-7-13', 'Ruska  2', 0,1, 2),
	(12, 'Andre', 'Stevanovic', 'Beograd', '2000-8-22', 'Bulevar kralja Aleksandra 1',0, 1, 2),
	
	(13, 'Ivana', 'Djukic', 'Beograd', '2001-11-12', 'PEtra Kocica 32',0, 1, 3),
	(14, 'Svetislav', 'Pesic', 'Beograd', '2001-2-18', 'Njegoseva 17',0, 1, 3),
	(15, 'Dusko', 'Vujosevic', 'Beograd', '2001-5-2', 'Ustanicka 2',0, 1, 3),
	(16, 'Petar', 'Milosavljvic', 'Beograd', '2001-4-3', 'Proleterskih brigada  2',0, 1, 3),
	(17, 'Aleksej', 'Nikolic', 'Beograd', '2001-8-22', 'Bulevar kralja Aleksandra 256',0, 1, 3),

	(18, 'KAtarina', 'Veljkovic', 'Beograd', '1998-12-12', 'Kneza Viseslava 2',0, 1, 4),
	(19, 'Milica', 'Mandic', 'Beograd', '1998-12-18', 'Obalskih Radnika 13',0, 1, 4),
	(20, 'Milan', 'Mitrovic', 'Beograd', '1998-5-12', 'Neznanog junaka 2', 0,1, 4),
	(21, 'Tomislav', 'Vucic', 'Beograd', '1998-7-13', 'Uzicka  2', 0,1, 4),
	(22, 'Aleksandar', 'Nikolic', 'Beograd', '1998-8-22', 'Bulevar kralja Aleksandra KAradjordevica1',0, 1, 4),
	
	(23, 'Marijana', 'Jovanovic', 'Beograd', '2003-12-12', 'Kneza Milosa 32',0, 2, 3),
	(24, 'Milica', 'Milosevic', 'Beograd', '2003-12-18', 'Hajduk Stanka bb',0, 2, 3),
	(25, 'Miljana', 'Andric', 'Beograd', '2003-5-12', 'Petrovacka 2',0, 2, 3),
	(26, 'Natasa', 'Petrovic', 'Beograd', '2003-7-13', 'Ruska  2',0, 2, 3),
	(27, 'Bojana', 'Stevanovic', 'Beograd', '2002-8-22', 'Bulevar kralja Aleksandra 1',0, 2, 3);

insert into Izostanci values
	(1, '2017-10-5', 6, TRUE),
	(1, '2017-10-6', 6, TRUE),
	(1, '2017-10-7', 6, TRUE),
	(2, '2017-11-5', 6, TRUE),
	(3, '2017-11-5', 3, FALSE),
	(22, '2015-12-5', 6, TRUE),
	(12, '2016-10-5', 6, TRUE),
	(6, '2016-10-5', 6, TRUE);

insert into Staratelj values
	(11, 'Radenko', 'Zeravica', '+381651235645'),
	(12, 'Zivana', 'Zeravica','+381621237845'),
	(21, 'Milan', 'Kuburovic','nepoznat'),
	(22, 'Marija', 'Kuburovic', 'nepoznat'),
	(31, 'Miljan', 'Mladenovic','+381651235645'),
	(32, 'Milijana', 'Mladenovic','+381621237845'),
	(41, 'Milan', 'Petrovic', 'nepoznat'),
	(42, 'Marija', 'Petrovic', 'nepoznat'),
	(51, 'Radenko', 'Markovic', '+381651235645'),
	(52, 'Zivana', 'MArkovic', '+381621237845'),
	(61, 'Milan', 'Jovanovic', 'nepoznat'),
	(62, 'Marija', 'Jovanovic', 'nepoznat'),
	(71, 'Radenko', 'Milosevic','+381651235645'),
	(72, 'Zivana', 'Milosevic', '+381621237845'),
	(81, 'Milan', 'Andric', 'nepoznat'),
	(82, 'Marija', 'Andric', 'nepoznat'),
	(91, 'Petko', 'Stevanovic','+381651235645'),
	(92, 'Jovnka', 'Stevanovic', '+381621237845'),
	(101, 'Milan', 'Djukic', 'nepoznat'),
	(102, 'Marija', 'Djukic','nepoznat'),
	(111, 'Ivan', 'PEsic', '+381651235645'),
	(112, 'Mitar', 'Pesic','+381621237845'),
	(121, 'Milan', 'Vujosevic', 'nepoznat'),
	(122, 'Marija', 'Vujosevic','nepoznat'),
	(131, 'Bozidar', 'Milosavljevic','+381651235645'),
	(132, 'Mihajlo', 'Milosavljevic', '+381621237845'),
	(141, 'Milan', 'Nikolic', 'nepoznat'),
	(142, 'Marija', 'Nikolic','nepoznat'),
	(151, 'Radenko', 'Veljkovic', '+381651235645'),
	(152, 'Zivana', 'Mandic', '+381621237845'),
	(161, 'Milan', 'Mitrovic', 'nepoznat'),
	(162, 'Marija', 'Vucic', 'nepoznat');

insert into Ucenik_Staratelj values
	(1, 11),
	(1, 12),
	(2, 21),
	(2, 22),
	(3, 31),
	(3, 32),
	(4, 41),
	(4, 42),
	(5, 51),
	(5, 52),
	(6, 51),
	(6, 52),
	(7, 61),
	(7, 62),
	(8, 61),
	(8, 62),
	(9, 71),
	(9, 72),
	(10, 81),
	(10, 82),
	(11, 41),
	(11, 42),
	(12, 91),
	(12, 92),
	(13, 101),
	(13, 102),
	(14, 111),
	(14, 112),
	(15, 121),
	(15, 122),
	(16, 131),
	(16, 132),
	(17, 141),
	(17, 142),
	(18, 151),
	(19, 152),
	(20, 161),
	(21, 162),
	(22, 141),
	(22, 142),

	
	(23, 61),
	(23, 62),
	(24, 71),
	(24, 72),
	(25, 81),
	(25, 82),
	(26, 91),
	(26, 92),
	(27, 101),
	(27, 102);


	

insert into Smer_Predmet values
	(4, 4, 4),
	(4, 5, 4),
	(4, 3, 3);

insert into Ocena values
	(6, 4, '2016-5-5', 5),
	(6, 4, '2016-6-5', 5),
	(6, 4, '2016-12-5', 5),
	(6, 3, '2016-5-5', 1),
	(6, 3, '2017-6-2', 5),
	(6,5, '2016-5-16', 4);
insert into Zakljucna values
	(6, 3, 3),
	(6, 15, 5),
	(6, 22, 5), 
	(6,11,5);


	