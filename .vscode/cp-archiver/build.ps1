# Package this folder as a .vsix (no node/vsce needed) and install it into VS Code.
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.IO.Compression, System.IO.Compression.FileSystem

$src = $PSScriptRoot
$pkg = Get-Content "$src\package.json" -Raw | ConvertFrom-Json
$out = Join-Path $src "$($pkg.name)-$($pkg.version).vsix"
if (Test-Path $out) { Remove-Item $out }

$types = @'
<?xml version="1.0" encoding="utf-8"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension=".json" ContentType="application/json" />
  <Default Extension=".js" ContentType="application/javascript" />
  <Default Extension=".vsixmanifest" ContentType="text/xml" />
</Types>
'@

$manifest = @"
<?xml version="1.0" encoding="utf-8"?>
<PackageManifest Version="2.0.0" xmlns="http://schemas.microsoft.com/developer/vsx-schema/2011" xmlns:d="http://schemas.microsoft.com/developer/vsx-schema-design/2011">
  <Metadata>
    <Identity Language="en-US" Id="$($pkg.name)" Version="$($pkg.version)" Publisher="$($pkg.publisher)" />
    <DisplayName>$($pkg.displayName)</DisplayName>
    <Description xml:space="preserve">$($pkg.description)</Description>
    <Properties>
      <Property Id="Microsoft.VisualStudio.Code.Engine" Value="$($pkg.engines.vscode)" />
    </Properties>
  </Metadata>
  <Installation>
    <InstallationTarget Id="Microsoft.VisualStudio.Code" />
  </Installation>
  <Dependencies />
  <Assets>
    <Asset Type="Microsoft.VisualStudio.Code.Manifest" Path="extension/package.json" Addressable="true" />
  </Assets>
</PackageManifest>
"@

$zip = [System.IO.Compression.ZipFile]::Open($out, 'Create')
try {
    foreach ($entry in @{ '[Content_Types].xml' = $types; 'extension.vsixmanifest' = $manifest }.GetEnumerator()) {
        $w = New-Object System.IO.StreamWriter($zip.CreateEntry($entry.Key).Open())
        $w.Write($entry.Value)
        $w.Dispose()
    }
    foreach ($f in 'package.json', 'extension.js') {
        [void][System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile($zip, "$src\$f", "extension/$f")
    }
} finally {
    $zip.Dispose()
}

code --install-extension $out --force
