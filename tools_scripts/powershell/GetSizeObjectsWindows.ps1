# target folder
$startFolderGame =  'D:\inteam'
$startFolderDoc =  'E:\'
$startFolderDev =  'C:\'
$startFolderC =  'C:\DevTools'

$targetFolders= "$startFolderDev",
				"$startFolderGame", "$startFolderGame\Game", "$startFolderGame\UnitTest","$startFolderGame\FrameworkTools",
				"$startFolderC",
# input filter:
$filterFolderName = ""
$filterFileName = ""

# output
$date = "$(Get-Date)".Replace('/','_').Replace(' ','_').Replace(':','_')
$outputFolder = $PSScriptRoot
$outputFile = "$outputFolder\ListFolderSize_$date.csv" #csv or xlsx/xls/txt
New-Item $outputFile -ItemType File

#header
$folderName = 'Folder name'
$folderSize = 'Folder size (MB)'

$NewLine = "{0},{1}" -f $folderName,$folderSize
$NewLine | add-content -path $outputFile

foreach  ($targetFolder in $targetFolders)
{
	$NewLine = "{0},{1}" -f '', ''
	$NewLine | add-content -path $outputFile
	Write-Progress -Id 1 -Activity 'Get size file' -Status 'Get size file in progress...' -PercentComplete -1 -Verbose
	Get-ChildItem -recurse -force $targetFolder -Filter $filterFolderName -ErrorAction SilentlyContinue | ? { $_ -isnot [io.directoryinfo] } | % {
		$len = 0
		Get-ChildItem -recurse -force -Filter $filterFileName -File $_.fullname -ErrorAction SilentlyContinue | % {
			$len += $_.length
			#get size
			$folderName = $_.fullname
			$folderSize= '{0:N2}' -f ($len / 1MB)

			$folderSize = $folderSize.Replace(',','')
			write-host "Folder $folderName : $folderSize MB"

			#input to data object
			$NewLine = "{0},{1}" -f $folderName , $folderSize
			$NewLine | add-content -path $outputFile
		}
	}

}

Write-Progress -Id 1 -Activity 'Done' -Status '...'-PercentComplete -1 -Completed
write-host 'Done';
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown');

return

