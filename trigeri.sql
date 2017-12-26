-- TRIGERI --

use Srednja_skola;

drop trigger if exists ocena_unos;
drop trigger if exists ocena_izmena;
drop trigger if exists unos_zakljucne;
drop trigger if exists izmena_zakljucne;
drop trigger if exists unos_odeljenja;
drop trigger if exists izmena_odeljenja;



delimiter $

-- Trigeri koje ne dozvoljavau unos i izmenu ocene koja nije izmedju 1 i pet; 
-- ne dozvoljavaju unos i izmenu ocena ako je ocena zakljucena
-- Ne dozvoljavaju unos i izmenu ocena neaktivnim studentama


create trigger ocena_unos before insert  on Ocena
	for each row
	begin
		set @aktivan = (select count(*) from Ucenik
							where id = new.id_ucenika and id_status = 1
						);
		if (@aktivan != 1) then 
			signal sqlstate '45000' set message_text = "Nije moguce menjati stanje uceniku koji nije aktivan";
		end if;
		set @zakljucena = (select count(*) from Zakljucna 
							where id_ucenika = new.id_ucenika and id_predmeta = new.id_predmeta);
		if (@zaklucena > 0) then
			signal sqlstate '45000' set message_text = "Nije moguce dodavati ocene nakon sto je ocena zakljucena.";
		end if;
		if (new.ocena not between 1 and 5) then
			signal sqlstate '45000' set message_text = "Ocena mora da ima vrednosti izmedju 1 i 5";
		end if;
end$

create trigger ocena_izmena before update on Ocena
	for each row
	
	begin
		set @aktivan = (select count(*) from Ucenik
							where id = new.id_ucenika and id_status = 1
						);
		if (@aktivan != 1) then 
			signal sqlstate '45000' set message_text = "Nije moguce menjati stanje uceniku koji nije aktivan";
		end if;

		set @zakljucena = (select count(*) from Zakljucna 
							where id_ucenika = new.id_ucenika and id_predmeta = new.id_predmeta);
		
		if (@zaklucena > 0) then
			signal sqlstate '45000' set message_text = "Nije moguce menjati ocene nakon sto je ocena zakljucena.";
		end if;
	
		if (new.ocena not between 1 and 5) then
			signal sqlstate '45000' set message_text = "Ocena mora da ima vrednosti izmedju 1 i 5";
		end if;
end$

-- Trigeri koji automatski azuriraju prosek nakon zakljucivanje neke ocene


create trigger unos_zakljucne after insert on Zakljucna
	for each row
	begin 
		set @prosek = (select sum(ocena)/count(*) from Zakljucna
					where new.id_ucenika = id_ucenika
					);
		update Ucenik set prosek = @prosek
			where id = new.id_ucenika;
end$

create trigger izmena_zakljucne after update on Zakljucna
	for each row
	begin 
		set @prosek = (select (sum(ocena)*1.00)/(1.00*count(*)) from Zakljucna
					where new.id_ucenika = id_ucenika
					);
		update Ucenik set prosek = @prosek
			where id = new.id_ucenika;
end$


-- Trigeri koji zabranjuje unos godine van opseg (0, 4)
-- Ako se promeni godina na 0 svim ucenicima tog odeljenja koji su imali aktivan status status se menja u zavrsio
-- Zabranjuje dodeljivanje odeljenja nastavniku koji vec ima aktivno odeljenje

create trigger unos_odeljenja  before insert on Odeljenje
	for each row
	begin
		if (new.godina not between 0 and 4) then
			signal sqlstate '45000' set message_text = "Ocena mora imati vrednost izmedju 0 i 4";
		end if;
		if (new.godina = 0) then
			update Ucenik set id_status = 2
			where id_odeljenja = new.id;
		end if;
		
		set @razredni = (select count(*) from Odeljenje
					  where id_razrednog = new.id_razrednog and godina > 0 
					);
		if (@razredni > 0) then
			signal sqlstate '45000' set message_text = "JEdan profesor moze da bude razredni najvise jednom odeljenju";
		end if;
			

	end $

create trigger izmena_odeljenja before update on Odeljenje
	for each row
	begin
		if (new.godina not between 0 and 4) then
			signal sqlstate '45000' set message_text = "Ocena mora imati vrednost izmedju 0 i 4";
		end if;
		if (new.godina = 0) then
			update Ucenik set id_status = 2
			where id_odeljenja = new.id;
		end if;
		set @razredni = (select count(*) from Odeljenje
					  where id_razrednog = new.id_razrednog and godina > 0);
		if (@razredni > 0) then
			signal sqlstate '45000' set message_text = "JEdan profesor moze da bude razredni najvise jednom odeljenju";
		end if;
	end$





