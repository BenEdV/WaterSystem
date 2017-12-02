% MATLAB dataparser

fileID = fopen('WaterData','r');
C = textscan(fileID, '%s %d/%d');
fclose(fileID);

dn=datetime(C{1}, 'InputFormat', 'dd/MM/yy-HH:mm:ss');
plot(dn,C{2})
hold on
plot(dn,C{3})