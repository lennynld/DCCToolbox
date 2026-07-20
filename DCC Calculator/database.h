#pragma once
#include <string>

// De uitgebreide database functie
inline std::wstring lookupManufacturer(int cv8, int cv7, int cv250) {
    std::wstring merk = L"Onbekende Fabrikant";
    std::wstring model = L"Onbekend Model (Vul des betreffende CV in)";

    switch (cv8) {
    case 1: // CML Electronics Limited
        merk = L"CML Electronics Limited";
        break;

    case 2: // Train Technology
        merk = L"Train Technology";
        break;
    
    case 11: //NCE Corporation
        merk = L"NCE Corporation";
        break;

    case 12: //Wangrow
        merk = L"Wangrow";
        break;
            
    case 13: //Public Domain & Do-It-Yourself Decoders
        merk = L"Public Domain and DIY Decoders";
        break;

    case 14: //PSI - Dynatrol
        merk = L"PSI - Dynatrol";
        break;
            
    case 15: //Ramfixx Technologies (Wangrow)
        merk = L"Ramfixx Technologies";
        break;

    case 17: //Advanced IC Engineering, Inc.
        merk = L"Advanced IC Engineering, INC.";
        break;

    case 18: //JMRI
        merk = L"JMRI";
        break;

    case 19: //AMW
        merk = L"AMW";
        break;

    case 20: //T4T - Technology for Trains GmbH
        merk = L"T4T - Technology for Trains GmbH";
        break;

    case 21: //Kreischer Datentechnik
        merk = L"Kreischer Datentechnik";
        break;
    
    case 22: //KAM Industries
        merk = L"KAM Industries";
        break;
    
    case 23: //S Helper Service
        merk = L"S Helper Service";
        break;
    case 24: //MoBaTron.de
        merk = L"MoBaTron.de";
        break;
    case 25: //Team Digital, LLC
        merk = L"Team Digital, LLC";
        break;
    case 26: //MBTronik - PiN GITmBH
        merk = L"MBTronik - PiN GITmBH";
        break;
    case 27: //MTH Electric Trains, Inc.
        merk = L"MTH Electric Trains, Inc.";
        break;
    case 28: //Heljan A/S
        merk = L"Heljan A/S";
        break;
    case 29: //Mistral Train Models
        merk = L"Mistral Train Models";
        break;
    case 30: //Digsight
        merk = L"Digsight";
        break;
    case 31: //Brelec
        merk = L"Brelec";
        break;
    case 32: //Regal Way Co. Ltd
        merk = L"Regal Way Co. Ltd";
        break;
    case 34: //Aristo-Craft
        merk = L"Aristo-Craft";
        break;
    case 35: //Elektronik & Modell Produktion
        merk = L"Elektronik & Modell Produktion";
        break;
    case 36: //DCCConcepts
        merk = L"DCCConcepts";
        break;
    case 37: //NAC Services, Inc.
        merk = L"NAC Services, Inc.";
        break;
    case 38: //Broadway Limited Imports, LLC
        merk = L"Broadway Limited Imports, LLC";
        break;
    case 39: //Educational Computer, Inc (DCCdevices.com)
        merk = L"Educational Computer, Inc (DCCdevices.com)";
        break;
    case 40: //KATO Precision Models
        merk = L"KATO Precision Models";
        break;
    case 41: //Passmann Modellbahnzubehoer
        merk = L"Passmann Modellbahnzubehoer";
        break;
    case 42: //Digirails
        merk = L"Digirails";
        break;
    case 43: //Ngineering
        merk = L"Ngineering";
        break;
    case 44: //SPROG-DCC
        merk = L"SPROG-DCC";
        break;
    case 45: //ANE Model Co., LTD.
        merk = L"ANE Model Co., LTD.";
        break;
    case 46: //GFB Designs
        merk = L"GFB Designs";
        break;
    case 47: //Capecom
        merk = L"Capecom";
        break;
    case 48: //Hornby Hobbies Ltd.
        merk = L"Hornby Hobbies Ltd.";
        break;
    case 49: //Joka Electronic
        merk = L"Joka Electronic";
        break;
    case 50: //N & Q Electronics
        merk = L"N & Q Electronics";
        break;
    case 51: //DCC Supplies, Ltd
        merk = L"DCC Supplies, Ltd";
        break;
    case 52: //Krois-Modell
        merk = L"Krois-Modell";
        break;
    case 53: //Rautenhaus Digital
        merk = L"Rautenhaus Digital";
        break;
    case 54: //TCH Technology
        merk = L"TCH Technology";
        break;
    case 55: //QElectronics GmbH
        merk = L"QElectronics GmbH";
        break;
    case 56: //LDH
        merk = L"LDH";
        break;
    case 57: //Rampino Elektronik
        merk = L"Rampino Elektronik";
        break;
    case 58: //KRES GmbH
        merk = L"KRES GmbH";
        break;
    case 59: //Tam Valley Depot
        merk = L"Tam Valley Depot";
        break;
    case 60: //Bluecher-Elektronik
        merk = L"Bluecher-Elektronik";
        break;
    case 61: //TrainModules
        merk = L"TrainModules";
        break;
    case 62: //Tams Elektronik GmbH
        merk = L"Tams Elektronik GmbH";
        break;
    case 63: //Noarail
        merk = L"Noarail";
        break;
    case 64: //Digital Bahn
        merk = L"Digital Bahn";
        break;
    case 66: //Railnet Solutions, LLC
        merk = L"Railnet Solutions, LLC";
        break;
    case 68: //MAWE Elektronik
        merk = L"MAWE Elektronik";
        break;
    case 69: //E-Modell
        merk = L"E-Modell";
        break;
    case 71: //New York Byano Limited
        merk = L"New York Byano Limited";
        break;
    case 72: //MTB Model
        merk = L"MTB Model";
        break;
    case 73: //The Electric Railroad Company
        merk = L"The Electric Railroad Company";
        break;
    case 74: //PpP Digital
        merk = L"PpP Digital";
        break;
    case 75: //DigiTools Electronics Servicing and Contractor Ltd.
        merk = L"DigiTools Electronics Servicing and Contractor Ltd.";
        break;
    case 76: //Auvidel
        merk = L"Auvidel";
        break;
    case 77: //LS Models Sprl
        merk = L"LS Models Sprl";
        break;
    case 78: //Train-O-Matic
        merk = L"Train-O-Matic";
        break;
    case 85: //Uhlenbrock Elektronik GmbH
        merk = L"Uhlenbrock Elektronik GmbH";
        break;
    case 87: //RR-CirKits
        merk = L"RR-CirKits";
        break;
    case 95: //Sanda Kan Industrial (1981) Ltd.
        merk = L"Sanda Kan Industrial (1981) Ltd.";
        break;
    case 97: //Doehler and Haass
        merk = L"Doehler and Haass";
        switch (cv250) {
        case 16: model = L"DHP160"; break;
        case 25: model = L"DHP250"; break;
        case 33: model = L"DHP250"; break;
        case 26: model = L"DHP260"; break;
        case 40: model = L"FH05A"; break;
        case 50: model = L"DH05A"; break;
        case 100: model = L"DH10A"; break;
        case 51: model = L"DH05B"; break;
        case 52: model = L"DH05C"; break;
        case 60: model = L"DH06A"; break;
        case 102: model = L"DH10C"; break;
        case 120: model = L"DH12A"; break;
        case 140: model = L"DH14A"; break;
        case 141: model = L"DH14B"; break;
        case 160: model = L"DH16A"; break;
        case 180: model = L"DH18A"; break;
        case 200: model = L"DH21A"; break;
        case 201: model = L"DH21B"; break;
        case 202: model = L"DH22A"; break;
        case 203: model = L"DH22B"; break;
        case 41: model = L"FH05B"; break;
        case 150: model = L"FH16A"; break;
        case 170: model = L"FH18A"; break;
        case 192: model = L"FH22A"; break;
        case 131: model = L"PD05A"; break;
        case 132: model = L"PD06A"; break;
        case 130: model = L"PD12A"; break;
        case 134: model = L"PD18A"; break;
        case 133: model = L"PD21A"; break;
        case 205: model = L"SD05A"; break;
        case 210: model = L"SD10A"; break;
        case 216: model = L"SD16A"; break;
        case 218: model = L"SD18A"; break;
        case 221: model = L"SD21A"; break;
        case 222: model = L"SD22A"; break;
        }
        break;
    case 99: //Lenz Elektronik GmbH
        merk = L"Lenz Elektronik GmbH";
        switch (cv7) {
        case 60: model = L"GOLD mini (niet te updaten)"; break;
        case 61: model = L"GOLD H0 (niet te updaten)"; break;
        case 65: model = L"SILVER H0 (niet te updaten)"; break;
        case 66: model = L"SILVER mini (niet te updaten)"; break;
        case 70: model = L"GOLD mini"; break;
        case 71: model = L"GOLD H0"; break;
        case 72: model = L"GOLD maxi"; break;
        case 73: model = L"model plus köf H0 met motor koppeling"; break;
        case 75: model = L"SILVER H0"; break;
        case 76: model = L"SILVER Mini"; break;
        case 77: model = L"STANDARD+V2"; break;
        case 78: model = L"SILVER direct"; break;
        case 79: model = L"STANDARD+V2, verbeterde versie"; break;
        case 80: model = L"LF101XF"; break;
        case 81: model = L"STANDARD"; break;
        case 82: model = L"SILVER21"; break;
        case 83: model = L"LRC100"; break;
        case 84: model = L"SILVER+Plux22"; break;
        case 90: model = L"GOLDmini+"; break;
        case 91: model = L"GOLD+"; break;
        case 93: model = L"STANDARD+"; break;
        case 94: model = L"SILVER+Next18"; break;
        case 95: model = L"SILVER+"; break;
        case 96: model = L"SILVERmini+"; break;
        case 97: model = L"SILVER+Plux12"; break;
        case 98: model = L"SILVERdirect+"; break;
        case 99: model = L"SILVER21+"; break;
        }
        break;
    case 101: //Bachmann Trains
        merk = L"Bachmann Trains";
        break;
    case 103: //Nagasue System Design Office
        merk = L"Nagasue System Design Office";
        break;
    case 105: //Computer Dialysis France
        merk = L"Computer Dialysis France";
        break;
    case 109: //Viessmann Modellspielwaren GmbH
        merk = L"Viessmann Modellspielwaren GmbH";
        break;
    case 111: //aber & Koenig Electronics GmbH
        merk = L"aber & Koenig Electronics GmbH";
        break;
    case 113: //QS Industries
        merk = L"QS Industries";
        break;
    case 115: //Dietz Modellbahntechnik
        merk = L"Dietz Modellbahntechnik";
        break;
    case 117: //cT Elektronik
        merk = L"cT Elektronik";
        break;
    case 119: //W. S. Ataras Engineering
        merk = L"W. S. Ataras Engineering";
        break;
    case 123: //Mssoth Elektronik, GmbH
        merk = L"Mssoth Elektronik, GmbH";
        break;
    case 125: //ProfiLok Modellbahntechnik GmbH
        merk = L"ProfiLok Modellbahntechnik GmbH";
        break;
    case 127: //Atlas Model Railroad Co., Inc.
        merk = L"Atlas Model Railroad Co., Inc.";
        break;
    case 129: //Digitrax
        merk = L"Digitrax";
        break;
    case 131: //Trix Modelleisenbahn
        merk = L"Trix Modelleisenbahn";
        break;
    case 132: //ZTC Controls Ltd.
        merk = L"ZTC Controls Ltd.";
        break;
    case 133: //Intelligent Command Control
        merk = L"Intelligent Command Control";
        break;
    case 135: //CVP Products
        merk = L"CVP Products";
        break;
    case 139: //RealRail Effects
        merk = L"RealRail Effects";
        break;
    case 141: //Throttle-Up (Soundtraxx)
        merk = L"Throttle-Up (Soundtraxx)";
        break;
    case 143: //Model Rectifier Corp.
        merk = L"Model Rectifier Corp.";
        break;
    case 145: //Zimo Elektronik
        merk = L"Zimo Elektronik";
        switch (cv250) {
        case 190: model = L"MX659N18"; break;
        case 197: model = L"MX617"; break;
        case 199: model = L"MX600"; break;
        case 200: model = L"MX82"; break;
        case 201: model = L"MX620"; break;
        case 202: model = L"MX62"; break;
        case 203: model = L"MX63"; break;
        case 204: model = L"MX64"; break;
        case 205: model = L"MX64H"; break;
        case 206: model = L"MX64D"; break;
        case 207: model = L"MX680"; break;
        case 208: model = L"MX690"; break;
        case 209: model = L"MX69"; break;
        case 210: model = L"MX640"; break;
        case 211: model = L"MX630-P2520"; break;
        case 212: model = L"MX632"; break;
        case 213: model = L"MX631"; break;
        case 214: model = L"MX642"; break;
        case 215: model = L"MX643"; break;
        case 216: model = L"MX647"; break;
        case 217: model = L"MX646"; break;
        case 218: model = L"MX630-P25K22"; break;
        case 219: model = L"MX631-P25K22"; break;
        case 220: model = L"MX632-P25K22"; break;
        case 221: model = L"MX645"; break;
        case 222: model = L"MX644"; break;
        case 223: model = L"MX621"; break;
        case 224: model = L"MX695-RevB"; break;
        case 225: model = L"MX648"; break;
        case 226: model = L"MX685"; break;
        case 227: model = L"MX695-RevC"; break;
        case 228: model = L"MX681"; break;
        case 229: model = L"MX695N"; break;
        case 230: model = L"MX696"; break;
        case 231: model = L"MX696N"; break;
        case 232: model = L"MX686"; break;
        case 233: model = L"MX622"; break;
        case 234: model = L"MX623"; break;
        case 235: model = L"MX687"; break;
        case 236: model = L"MX621-Fleischmann"; break;
        case 243: model = L"MX618"; break;
        case 245: model = L"MX697"; break;
        case 246: model = L"MX658N18"; break;
        case 248: model = L"MX821"; break;
        case 250: model = L"MX699"; break;
        case 253: model = L"MX649"; break;
        case 1: model = L"MS500"; break;
        case 2: model = L"MS480"; break;
        case 3: model = L"MS490"; break;
        case 4: model = L"MS440"; break;
        case 5: model = L"MS580"; break;
        case 6: model = L"MS450"; break;
        case 7: model = L"MS990"; break;
        case 8: model = L"MS590"; break;
        case 9: model = L"MS950"; break;
        case 10: model = L"MS560"; break;
        case 11: model = L"MS001"; break;
        case 12: model = L"MS491"; break;
        case 13: model = L"MS581"; break;
        case 14: model = L"MS540"; break;
        case 15: model = L"MS591"; break;
        case 16: model = L"MS481"; break;
        case 17: model = L"MS501"; break;
        case 18: model = L"MS920"; break;
        case 64: model = L"FS850"; break;
        case 119: model = L"MN140"; break;
        case 120: model = L"MN250"; break;
        case 121: model = L"MN150"; break;
        case 122: model = L"MN160"; break;
        case 123: model = L"MN340"; break;
        case 124: model = L"MN170"; break;
        case 125: model = L"MN300"; break;
        case 126: model = L"MN330"; break;
        case 127: model = L"MN180"; break;
        }
        break;
    case 147: //Umelec Ing. Buero
        merk = L"Umelec Ing. Buero";
        break;
    case 149: //Rock Junction Controls
        merk = L"Rock Junction Controls";
        break;
    case 151: //Electronic Solutions Ulm GmbH & Co KG
        merk = L"Electronic Solutions Ulm GmbH & Co KG";
        break;
    case 153: //Train Control Systems
        merk = L"Train Control Systems";
        break;
    case 155: //Gebr. Fleischmann GmbH & Co.
        merk = L"Gebr. Fleischmann GmbH & Co.";
        break;
    case 157: //Kuehn Ing.
        merk = L"Kuehn Ing.";
        break;
    case 159: //LGB (Ernst Paul Lehmann Patentwerk)
        merk = L"LGB (Ernst Paul Lehmann Patentwerk)";
        break;
    case 161: //Modelleisenbahn GmbH (formerly Roco)
        merk = L"Modelleisenbahn GmbH (formerly Roco)";
        break;
    case 162: //Piko
        merk = L"Piko";
        break;
    case 163: //WP Railshops
        merk = L"WP Railshops";
        break;
    case 165: //Model Electronic Railway Group
        merk = L"Model Electronic Railway Group";
        break;
    case 170: //AuroTrains
        merk = L"AuroTrains";
        break;
    case 173: //Arnold - Rivarossi
        merk = L"Arnold - Rivarossi";
        break;
    case 186: //BRAWA Modellspielwaren GmbH & Co.
        merk = L"BRAWA Modellspielwaren GmbH & Co";
        break;
    case 204: //Con-Com GmBH
        merk = L"Con-Com GmBH";
        break;
    case 225: //Elproma Electronics Poland
        merk = L"Elproma Electronics Poland";
        break;
    case 238: //NMRA reserved
        merk = L"NMRA reserved";
        break;



    
    //case 151: // ESU
       // merk = L"ESU (Electronic Solutions Ulm)";
       // if (cv7 == 255) model = L"LokSound 5 / LokPilot 5";
       // else if (cv7 == 33) model = L"LokSound V4.0";
       // else if (cv7 == 32) model = L"LokPilot V4.0";
      //  else if (cv7 == 100) model = L"LokSound V3.5";
       // else model = L"ESU Serie (Versie " + std::to_wstring(cv7) + L")";
       // break;

    //case 145: // ZIMO
        //merk = L"Zimo Elektronik";
       // switch (cv250) {
        //case 210: model = L"MX630"; break;
       // case 211: model = L"MX631"; break;
        //case 212: model = L"MX632"; break;
      //  case 221: model = L"MX645 (Sound)"; break;
        //case 222: model = L"MX644 (MTC21 Sound)"; break;
       // case 224: model = L"MX648 (Mini Sound)"; break;
//case 230: model = L"MX633"; break;
      //  case 243: model = L"MX617"; break;
       // case 250: model = L"MS450 (Nieuwe gen. Sound)"; break;
      //  case 252: model = L"MS440 (Nieuwe gen. Sound)"; break;
      //  case 253: model = L"MS500 (Sub-mini Sound)"; break;
      //  default:  model = (cv250 > 0) ? L"Zimo ID: " + std::to_wstring(cv250) : L"Zimo (Vul CV250 in)"; break;
      //  }
      //  break;

  //  case 131: merk = L"Märklin"; model = L"mLD3 / mSD3 / mfx"; break;
   // case 13:  merk = L"Doehler and Haass"; model = L"DH-Serie (ID: " + std::to_wstring(cv250) + L")"; break;
   // case 99:  merk = L"Lenz"; model = L"Gold / Silver / Standard"; break;
   // case 85:  merk = L"Uhlenbrock"; model = L"IntelliDrive 2"; break;
   // case 161: merk = L"Piko"; model = L"SmartDecoder"; break;
   // case 141: merk = L"SoundTraxx"; model = L"Tsunami2 / Econami"; break;
   // case 143: merk = L"TCS (Train Control Systems)"; break;
   // case 81:  merk = L"Digitrax"; break;
  //  case 11:  merk = L"NMRA Standaard / NCE"; break;
  //  case 62:  merk = L"Fleischmann"; break;
   // case 48:  merk = L"Kuehn"; break;

    default: model = (cv250 > 0) ? L"Geen waarde" + std::to_wstring(cv250) : L"(Vul des betreffende CV in)"; break;
    }
    return L"Fabrikant: " + merk + L"\nModel: " + model ;
}