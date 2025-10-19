# input list file
$msg = "Input CSV file path containing the list files you want to delete. If the list file is currently not available. Please press enter to list the file again"

$isFilesList = "false"
$response = Read-Host -Prompt $msg
if($response -eq '')
{
	# call list file
	$outputFile = Invoke-Expression -Command $PSScriptRoot\GetFolderSize.ps1
}
else
{
	$outputFile = $response
}
$isFilesList = "true"

 # open file
 write-host "Please check list files before deleting."
 write-host 'Press any key to continue...';
 Invoke-Item "$outputFile"
 write-host ""

# prompt user
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown');
Add-Type -AssemblyName PresentationCore,PresentationFramework
Add-Type -AssemblyName System.Windows.Forms
if("$isFilesList" -eq "true") {
	$msg = "Do you want to start deleting files? Press Y (Yes) to continue or any keys to cancel"
	$response = Read-Host -Prompt $msg
	if($response -eq 'y')
	{
		Write-Progress -Id 1 -Activity 'Delete' -Status 'Deleting files in progress...' -PercentComplete -1 -Verbose
		write-host "_______________________________________________________________________________"
		write-host ""
		write-host "                 Starting delete files..."
		write-host "_______________________________________________________________________________"

		$filesList = Get-Content -Path $outputFile

		foreach($file in $filesList)
		{
			$index = "$file".IndexOf(',')
			$fileDir = "$file".Remove($index)
			if($fileDir -ne '')
			{
				#DELETE file
				Write-Host "Delete file $file".Replace(',',' :') "MB"
				Remove-Item -Recurse -Force -Confirm:$false "$fileDir" -ErrorAction SilentlyContinue
			}
		}
	}
	else
	{
		Write-Host "Cancel task"
	}
}
Write-Progress -Id 1 -Activity 'Done' -Status '...'-PercentComplete -1 -Completed
write-host 'Done';
$null = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown');
