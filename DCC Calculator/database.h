#ifndef DATABASE_H
#define DATABASE_H

// ==========================================
// DCC DECODER DATABASE - VERSIE 1.3
// ==========================================

#include <string>
#include <map>
#include <vector>

// --- STRUCTUUR VOOR FABRIKANTERINFORMATIE ---
struct ManufacturerInfo {
    std::wstring naam;
    int modelCv; // Het CV-nummer voor Model ID (-1 indien niet ondersteund)
};

// --- STRUCTUUR VOOR DECODER INFORMATIE ---
struct DecoderInfo {
    int cv8;              // Fabrikant ID
    int cv7;              // Softwareversie (-1 indien niet van toepassing)
    int cv250;            // Model ID waarde (-1 indien niet van toepassing)
    std::wstring merk;    // Merknaam
    std::wstring model;   // Modelomschrijving
    int modelCv;          // Het specifieke CV dat voor het Model ID gebruikt wordt
};

// --- FABRIKANTERADEN (CV8 MAPPING MET SPECIFIEK MODEL CV) ---
inline const std::map<int, ManufacturerInfo>& getManufacturerMap() {
    static const std::map<int, ManufacturerInfo> manufacturers = {
        { 1,   { L"CML Electronics Limited", -1 } },
        { 2,   { L"Train Technology", -1 } },
        { 11,  { L"NCE Corporation", -1 } },
        { 12,  { L"Wangrow", -1 } },
        { 13,  { L"Public Domain and DIY Decoders", -1 } },
        { 14,  { L"PSI - Dynatrol", -1 } },
        { 15,  { L"Ramfixx Technologies", -1 } },
        { 17,  { L"Advanced IC Engineering, INC.", -1 } },
        { 18,  { L"JMRI", -1 } },
        { 19,  { L"AMW", -1 } },
        { 20,  { L"T4T - Technology for Trains GmbH", -1 } },
        { 21,  { L"Kreischer Datentechnik", -1 } },
        { 22,  { L"KAM Industries", -1 } },
        { 23,  { L"S Helper Service", -1 } },
        { 24,  { L"MoBaTron.de", -1 } },
        { 25,  { L"Team Digital, LLC", -1 } },
        { 26,  { L"MBTronik - PiN GITmBH", -1 } },
        { 27,  { L"MTH Electric Trains, Inc.", -1 } },
        { 28,  { L"Heljan A/S", -1 } },
        { 29,  { L"Mistral Train Models", -1 } },
        { 30,  { L"Digsight", -1 } },
        { 31,  { L"Brelec", -1 } },
        { 32,  { L"Regal Way Co. Ltd", -1 } },
        { 34,  { L"Aristo-Craft", -1 } },
        { 35,  { L"Elektronik & Modell Produktion", -1 } },
        { 36,  { L"DCCConcepts", -1 } },
        { 37,  { L"NAC Services, Inc.", -1 } },
        { 38,  { L"Broadway Limited Imports, LLC", -1 } },
        { 39,  { L"Educational Computer, Inc (DCCdevices.com)", -1 } },
        { 40,  { L"KATO Precision Models", -1 } },
        { 41,  { L"Passmann Modellbahnzubehoer", -1 } },
        { 42,  { L"Digirails", -1 } },
        { 43,  { L"Ngineering", -1 } },
        { 44,  { L"SPROG-DCC", -1 } },
        { 45,  { L"ANE Model Co., LTD.", -1 } },
        { 46,  { L"GFB Designs", -1 } },
        { 47,  { L"Capecom", -1 } },
        { 48,  { L"Hornby Hobbies Ltd.", -1 } },
        { 49,  { L"Joka Electronic", -1 } },
        { 50,  { L"N & Q Electronics", -1 } },
        { 51,  { L"DCC Supplies, Ltd", -1 } },
        { 52,  { L"Krois-Modell", -1 } },
        { 53,  { L"Rautenhaus Digital", -1 } },
        { 54,  { L"TCH Technology", -1 } },
        { 55,  { L"QElectronics GmbH", -1 } },
        { 56,  { L"LDH", -1 } },
        { 57,  { L"Rampino Elektronik", -1 } },
        { 58,  { L"KRES GmbH", -1 } },
        { 59,  { L"Tam Valley Depot", -1 } },
        { 60,  { L"Bluecher-Elektronik", -1 } },
        { 61,  { L"TrainModules", -1 } },
        { 62,  { L"Tams Elektronik GmbH", -1 } },
        { 63,  { L"Noarail", -1 } },
        { 64,  { L"Digital Bahn", -1 } },
        { 66,  { L"Railnet Solutions, LLC", -1 } },
        { 68,  { L"MAWE Elektronik", -1 } },
        { 69,  { L"E-Modell", -1 } },
        { 71,  { L"New York Byano Limited", -1 } },
        { 72,  { L"MTB Model", -1 } },
        { 73,  { L"The Electric Railroad Company", -1 } },
        { 74,  { L"PpP Digital", -1 } },
        { 75,  { L"DigiTools Electronics Servicing and Contractor Ltd.", -1 } },
        { 76,  { L"Auvidel", -1 } },
        { 77,  { L"LS Models Sprl", -1 } },
        { 78,  { L"Train-O-Matic", 114 } },
        { 85,  { L"Uhlenbrock Elektronik GmbH", -1 } },
        { 87,  { L"RR-CirKits", -1 } },
        { 95,  { L"Sanda Kan Industrial (1981) Ltd.", -1 } },
        { 97,  { L"Doehler and Haass", 250 } },
        { 99,  { L"Lenz Elektronik GmbH", -1 } },
        { 101, { L"Bachmann Trains", -1 } },
        { 103, { L"Nagasue System Design Office", -1 } },
        { 105, { L"Computer Dialysis France", -1 } },
        { 109, { L"Viessmann Modellspielwaren GmbH", -1 } },
        { 111, { L"aber & Koenig Electronics GmbH", -1 } },
        { 113, { L"QS Industries", -1 } },
        { 115, { L"Dietz Modellbahntechnik", -1 } },
        { 117, { L"cT Elektronik", -1 } },
        { 119, { L"W. S. Ataras Engineering", -1 } },
        { 123, { L"Mssoth Elektronik, GmbH", -1 } },
        { 125, { L"ProfiLok Modellbahntechnik GmbH", -1 } },
        { 127, { L"Atlas Model Railroad Co., Inc.", -1 } },
        { 129, { L"Digitrax", -1 } },
        { 131, { L"Trix Modelleisenbahn", -1 } },
        { 132, { L"ZTC Controls Ltd.", -1 } },
        { 133, { L"Intelligent Command Control", -1 } },
        { 135, { L"CVP Products", -1 } },
        { 139, { L"RealRail Effects", -1 } },
        { 141, { L"Throttle-Up (Soundtraxx)", -1 } },
        { 143, { L"Model Rectifier Corp.", -1 } },
        { 145, { L"Zimo Elektronik", 250 } },
        { 147, { L"Umelec Ing. Buero", -1 } },
        { 149, { L"Rock Junction Controls", -1 } },
        { 151, { L"Electronic Solutions Ulm GmbH & Co KG", 255 } },
        { 153, { L"Train Control Systems", -1 } },
        { 155, { L"Gebr. Fleischmann GmbH & Co.", -1 } },
        { 157, { L"Kuehn Ing.", 110 } },
        { 159, { L"LGB (Ernst Paul Lehmann Patentwerk)", -1 } },
        { 161, { L"Modelleisenbahn GmbH (formerly Roco)", -1 } },
        { 162, { L"Piko", -1 } },
        { 163, { L"WP Railshops", -1 } },
        { 165, { L"Model Electronic Railway Group", -1 } },
        { 170, { L"AuroTrains", -1 } },
        { 173, { L"Arnold - Rivarossi", -1 } },
        { 186, { L"BRAWA Modellspielwaren GmbH & Co", -1 } },
        { 204, { L"Con-Com GmBH", -1 } },
        { 225, { L"Elproma Electronics Poland", -1 } },
        { 238, { L"NMRA reserved", -1 } }
    };
    return manufacturers;
}

// --- SPECIFIEKE MODELLEN DATABASE ---
inline const std::vector<DecoderInfo>& getDecoderDatabase() {
    static const std::vector<DecoderInfo> decoders = {
        // --- DOEHLER & HAASS (CV8 = 97) ---
        { 97, -1, 16,  L"Doehler and Haass", L"DHP160", 250 },
        { 97, -1, 25,  L"Doehler and Haass", L"DHP250", 250 },
        { 97, -1, 33,  L"Doehler and Haass", L"DHP250", 250 },
        { 97, -1, 26,  L"Doehler and Haass", L"DHP260", 250 },
        { 97, -1, 40,  L"Doehler and Haass", L"FH05A", 250 },
        { 97, -1, 50,  L"Doehler and Haass", L"DH05A", 250 },
        { 97, -1, 100, L"Doehler and Haass", L"DH10A", 250 },
        { 97, -1, 51,  L"Doehler and Haass", L"DH05B", 250 },
        { 97, -1, 52,  L"Doehler and Haass", L"DH05C", 250 },
        { 97, -1, 60,  L"Doehler and Haass", L"DH06A", 250 },
        { 97, -1, 102, L"Doehler and Haass", L"DH10C", 250 },
        { 97, -1, 120, L"Doehler and Haass", L"DH12A", 250 },
        { 97, -1, 140, L"Doehler and Haass", L"DH14A", 250 },
        { 97, -1, 141, L"Doehler and Haass", L"DH14B", 250 },
        { 97, -1, 160, L"Doehler and Haass", L"DH16A", 250 },
        { 97, -1, 180, L"Doehler and Haass", L"DH18A", 250 },
        { 97, -1, 200, L"Doehler and Haass", L"DH21A", 250 },
        { 97, -1, 201, L"Doehler and Haass", L"DH21B", 250 },
        { 97, -1, 202, L"Doehler and Haass", L"DH22A", 250 },
        { 97, -1, 203, L"Doehler and Haass", L"DH22B", 250 },
        { 97, -1, 41,  L"Doehler and Haass", L"FH05B", 250 },
        { 97, -1, 150, L"Doehler and Haass", L"FH16A", 250 },
        { 97, -1, 170, L"Doehler and Haass", L"FH18A", 250 },
        { 97, -1, 192, L"Doehler and Haass", L"FH22A", 250 },
        { 97, -1, 131, L"Doehler and Haass", L"PD05A", 250 },
        { 97, -1, 132, L"Doehler and Haass", L"PD06A", 250 },
        { 97, -1, 130, L"Doehler and Haass", L"PD12A", 250 },
        { 97, -1, 134, L"Doehler and Haass", L"PD18A", 250 },
        { 97, -1, 133, L"Doehler and Haass", L"PD21A", 250 },
        { 97, -1, 205, L"Doehler and Haass", L"SD05A", 250 },
        { 97, -1, 210, L"Doehler and Haass", L"SD10A", 250 },
        { 97, -1, 216, L"Doehler and Haass", L"SD16A", 250 },
        { 97, -1, 218, L"Doehler and Haass", L"SD18A", 250 },
        { 97, -1, 221, L"Doehler and Haass", L"SD21A", 250 },
        { 97, -1, 222, L"Doehler and Haass", L"SD22A", 250 },

        // --- LENZ ELEKTRONIK (CV8 = 99) ---
        { 99, 60, -1, L"Lenz Elektronik GmbH", L"GOLD mini (niet te updaten)", -1 },
        { 99, 61, -1, L"Lenz Elektronik GmbH", L"GOLD H0 (niet te updaten)", -1 },
        { 99, 65, -1, L"Lenz Elektronik GmbH", L"SILVER H0 (niet te updaten)", -1 },
        { 99, 66, -1, L"Lenz Elektronik GmbH", L"SILVER mini (niet te updaten)", -1 },
        { 99, 70, -1, L"Lenz Elektronik GmbH", L"GOLD mini", -1 },
        { 99, 71, -1, L"Lenz Elektronik GmbH", L"GOLD H0", -1 },
        { 99, 72, -1, L"Lenz Elektronik GmbH", L"GOLD maxi", -1 },
        { 99, 73, -1, L"Lenz Elektronik GmbH", L"model plus köf H0 met motor koppeling", -1 },
        { 99, 75, -1, L"Lenz Elektronik GmbH", L"SILVER H0", -1 },
        { 99, 76, -1, L"Lenz Elektronik GmbH", L"SILVER Mini", -1 },
        { 99, 77, -1, L"Lenz Elektronik GmbH", L"STANDARD+V2", -1 },
        { 99, 78, -1, L"Lenz Elektronik GmbH", L"SILVER direct", -1 },
        { 99, 79, -1, L"Lenz Elektronik GmbH", L"STANDARD+V2, verbeterde versie", -1 },
        { 99, 80, -1, L"Lenz Elektronik GmbH", L"LF101XF", -1 },
        { 99, 81, -1, L"Lenz Elektronik GmbH", L"STANDARD", -1 },
        { 99, 82, -1, L"Lenz Elektronik GmbH", L"SILVER21", -1 },
        { 99, 83, -1, L"Lenz Elektronik GmbH", L"LRC100", -1 },
        { 99, 84, -1, L"Lenz Elektronik GmbH", L"SILVER+Plux22", -1 },
        { 99, 90, -1, L"Lenz Elektronik GmbH", L"GOLDmini+", -1 },
        { 99, 91, -1, L"Lenz Elektronik GmbH", L"GOLD+", -1 },
        { 99, 93, -1, L"Lenz Elektronik GmbH", L"STANDARD+", -1 },
        { 99, 94, -1, L"Lenz Elektronik GmbH", L"SILVER+Next18", -1 },
        { 99, 95, -1, L"Lenz Elektronik GmbH", L"SILVER+", -1 },
        { 99, 96, -1, L"Lenz Elektronik GmbH", L"SILVERmini+", -1 },
        { 99, 97, -1, L"Lenz Elektronik GmbH", L"SILVER+Plux12", -1 },
        { 99, 98, -1, L"Lenz Elektronik GmbH", L"SILVERdirect+", -1 },
        { 99, 99, -1, L"Lenz Elektronik GmbH", L"SILVER21+", -1 },

        // --- ZIMO ELEKTRONIK (CV8 = 145) ---
        { 145, -1, 1,   L"Zimo Elektronik", L"MS500", 250 },
        { 145, -1, 2,   L"Zimo Elektronik", L"MS480", 250 },
        { 145, -1, 3,   L"Zimo Elektronik", L"MS490", 250 },
        { 145, -1, 4,   L"Zimo Elektronik", L"MS440", 250 },
        { 145, -1, 5,   L"Zimo Elektronik", L"MS580", 250 },
        { 145, -1, 6,   L"Zimo Elektronik", L"MS450", 250 },
        { 145, -1, 7,   L"Zimo Elektronik", L"MS990", 250 },
        { 145, -1, 8,   L"Zimo Elektronik", L"MS590", 250 },
        { 145, -1, 9,   L"Zimo Elektronik", L"MS950", 250 },
        { 145, -1, 10,  L"Zimo Elektronik", L"MS560", 250 },
        { 145, -1, 11,  L"Zimo Elektronik", L"MS001", 250 },
        { 145, -1, 12,  L"Zimo Elektronik", L"MS491", 250 },
        { 145, -1, 13,  L"Zimo Elektronik", L"MS581", 250 },
        { 145, -1, 14,  L"Zimo Elektronik", L"MS540", 250 },
        { 145, -1, 15,  L"Zimo Elektronik", L"MS591", 250 },
        { 145, -1, 16,  L"Zimo Elektronik", L"MS481", 250 },
        { 145, -1, 17,  L"Zimo Elektronik", L"MS501", 250 },
        { 145, -1, 18,  L"Zimo Elektronik", L"MS920", 250 },
        { 145, -1, 64,  L"Zimo Elektronik", L"FS850", 250 },
        { 145, -1, 119, L"Zimo Elektronik", L"MN140", 250 },
        { 145, -1, 120, L"Zimo Elektronik", L"MN250", 250 },
        { 145, -1, 121, L"Zimo Elektronik", L"MN150", 250 },
        { 145, -1, 122, L"Zimo Elektronik", L"MN160", 250 },
        { 145, -1, 123, L"Zimo Elektronik", L"MN340", 250 },
        { 145, -1, 124, L"Zimo Elektronik", L"MN170", 250 },
        { 145, -1, 125, L"Zimo Elektronik", L"MN300", 250 },
        { 145, -1, 126, L"Zimo Elektronik", L"MN330", 250 },
        { 145, -1, 127, L"Zimo Elektronik", L"MN180", 250 },
        { 145, -1, 190, L"Zimo Elektronik", L"MX659N18", 250 },
        { 145, -1, 197, L"Zimo Elektronik", L"MX617", 250 },
        { 145, -1, 199, L"Zimo Elektronik", L"MX600", 250 },
        { 145, -1, 200, L"Zimo Elektronik", L"MX82", 250 },
        { 145, -1, 201, L"Zimo Elektronik", L"MX620", 250 },
        { 145, -1, 202, L"Zimo Elektronik", L"MX62", 250 },
        { 145, -1, 203, L"Zimo Elektronik", L"MX63", 250 },
        { 145, -1, 204, L"Zimo Elektronik", L"MX64", 250 },
        { 145, -1, 205, L"Zimo Elektronik", L"MX64H", 250 },
        { 145, -1, 206, L"Zimo Elektronik", L"MX64D", 250 },
        { 145, -1, 207, L"Zimo Elektronik", L"MX680", 250 },
        { 145, -1, 208, L"Zimo Elektronik", L"MX690", 250 },
        { 145, -1, 209, L"Zimo Elektronik", L"MX69", 250 },
        { 145, -1, 210, L"Zimo Elektronik", L"MX640", 250 },
        { 145, -1, 211, L"Zimo Elektronik", L"MX630-P2520", 250 },
        { 145, -1, 212, L"Zimo Elektronik", L"MX632", 250 },
        { 145, -1, 213, L"Zimo Elektronik", L"MX631", 250 },
        { 145, -1, 214, L"Zimo Elektronik", L"MX642", 250 },
        { 145, -1, 215, L"Zimo Elektronik", L"MX643", 250 },
        { 145, -1, 216, L"Zimo Elektronik", L"MX647", 250 },
        { 145, -1, 217, L"Zimo Elektronik", L"MX646", 250 },
        { 145, -1, 218, L"Zimo Elektronik", L"MX630-P25K22", 250 },
        { 145, -1, 219, L"Zimo Elektronik", L"MX631-P25K22", 250 },
        { 145, -1, 220, L"Zimo Elektronik", L"MX632-P25K22", 250 },
        { 145, -1, 221, L"Zimo Elektronik", L"MX645", 250 },
        { 145, -1, 222, L"Zimo Elektronik", L"MX644", 250 },
        { 145, -1, 223, L"Zimo Elektronik", L"MX621", 250 },
        { 145, -1, 224, L"Zimo Elektronik", L"MX695-RevB", 250 },
        { 145, -1, 225, L"Zimo Elektronik", L"MX648", 250 },
        { 145, -1, 226, L"Zimo Elektronik", L"MX685", 250 },
        { 145, -1, 227, L"Zimo Elektronik", L"MX695-RevC", 250 },
        { 145, -1, 228, L"Zimo Elektronik", L"MX681", 250 },
        { 145, -1, 229, L"Zimo Elektronik", L"MX695N", 250 },
        { 145, -1, 230, L"Zimo Elektronik", L"MX696", 250 },
        { 145, -1, 231, L"Zimo Elektronik", L"MX696N", 250 },
        { 145, -1, 232, L"Zimo Elektronik", L"MX686", 250 },
        { 145, -1, 233, L"Zimo Elektronik", L"MX622", 250 },
        { 145, -1, 234, L"Zimo Elektronik", L"MX623", 250 },
        { 145, -1, 235, L"Zimo Elektronik", L"MX687", 250 },
        { 145, -1, 236, L"Zimo Elektronik", L"MX621-Fleischmann", 250 },
        { 145, -1, 243, L"Zimo Elektronik", L"MX618", 250 },
        { 145, -1, 245, L"Zimo Elektronik", L"MX697", 250 },
        { 145, -1, 246, L"Zimo Elektronik", L"MX658N18", 250 },
        { 145, -1, 248, L"Zimo Elektronik", L"MX821", 250 },
        { 145, -1, 250, L"Zimo Elektronik", L"MX699", 250 },
        { 145, -1, 253, L"Zimo Elektronik", L"MX649", 250 }
    };
    return decoders;
}

// --- ZOEKFUNCTIE ---
inline std::wstring lookupManufacturer(int cv8, int cv7 = 0, int cv250 = 0) {
    if (cv8 <= 0) {
        return L"Voer een geldige CV8 (Fabrikant ID) in.";
    }

    const auto& manufacturers = getManufacturerMap();
    const auto& decoders = getDecoderDatabase();

    std::wstring merkNaam = L"Onbekende fabrikant";
    int merkspecifiekModelCv = -1;

    auto it = manufacturers.find(cv8);
    if (it != manufacturers.end()) {
        merkNaam = it->second.naam;
        merkspecifiekModelCv = it->second.modelCv;
    }

    std::wstring gevondenModel = L"";

    // Zoek specifieke match in decoder database
    for (const auto& dec : decoders) {
        if (dec.cv8 == cv8) {
            bool matchCv250 = (dec.cv250 == -1 || dec.cv250 == cv250);
            bool matchCv7 = (dec.cv7 == -1 || dec.cv7 == cv7);

            if (matchCv250 && matchCv7 && (cv250 > 0 || cv7 > 0)) {
                gevondenModel = dec.model;
                break;
            }
        }
    }

    // Resultaat tekst opbouwen
    std::wstring resultaat = L"Fabrikant: " + merkNaam + L" (CV8 = " + std::to_wstring(cv8) + L")\n";

    if (cv7 > 0) {
        resultaat += L"Softwareversie (CV7): " + std::to_wstring(cv7) + L"\n";
    }

    if (!gevondenModel.empty()) {
        resultaat += L"Gedetecteerd Model: " + gevondenModel + L"\n";
    }
    else if (merkspecifiekModelCv > 0 && cv250 <= 0) {
        resultaat += L"Fabrikant accepteert Model ID. Lees CV " + std::to_wstring(merkspecifiekModelCv) + L" uit en vul deze in bij Model ID om het Model weer te geven.\n";
    }
    else if (cv250 > 0 || cv7 > 0) {
        resultaat += L"Model/Versie niet specifiek in database gevonden.\n";
    }

    return resultaat;
}

#endif // DATABASE_H