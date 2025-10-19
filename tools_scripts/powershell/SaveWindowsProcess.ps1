$folderSaveXLSX = 'E:\learning\ProgramingTech\powershell\powershell\data.xlsx'
$folderSaveCSV = 'E:\learning\ProgramingTech\powershell\powershell\data.csv'
$XL = 'E:\learning\ProgramingTech\powershell\powershell\data.csv'
$startFolderAndroid =  '\\Android\Build'

# Get-Process | Export-Csv $folderSaveXLSX

$targetfolder=$startFolderNAS
$dataColl = @()
gci -force $targetfolder -ErrorAction SilentlyContinue | ? { $_ -is [io.directoryinfo] } | % {
	$len = 0
	gci -recurse -force $_.fullname -ErrorAction SilentlyContinue | % { $len += $_.length }
	# calculate size for each folder
	$foldername = $_.fullname
	$foldersize= '{0:N2}' -f ($len / 1Gb)

	#input to data object
	$dataObject = New-Object PSObject
	Add-Member -inputObject $dataObject -memberType NoteProperty -name “foldername” -value $foldername
	Add-Member -inputObject $dataObject -memberType NoteProperty -name “foldersizeGb” -value $foldersize
	$dataColl += $dataObject
}
$dataColl | Out-GridView -Title “Size of subdirectories”