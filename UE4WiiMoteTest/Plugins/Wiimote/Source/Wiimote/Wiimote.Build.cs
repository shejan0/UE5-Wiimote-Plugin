// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
using System.IO;
using System;

namespace UnrealBuildTool.Rules
{
	public class Wiimote : ModuleRules
	{
        private string ModulePath
        {
            get { return ModuleDirectory; }
        }
		private string ThirdPartyPath
		{
			get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
		}

		public Wiimote(ReadOnlyTargetRules Target) : base(Target)
		{

            PublicIncludePaths.AddRange(
                new string[] {
                    "Wiimote/Public"
					// ... add public include paths required here ...
				}
                );

			PrivateIncludePaths.AddRange(
				new string[] {
					"Wiimote/Private",
					// ... add other private include paths required here ...
				}
				);

            PublicDependencyModuleNames.AddRange(
                new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"ApplicationCore", // Needed for UE 4.20
					"InputCore",
					"InputDevice"
					// ... add other public dependencies that you statically link with here ...
				}
                );

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"ApplicationCore", // Needed for UE 4.20
					"InputCore",
					"InputDevice"
					// ... add private dependencies that you statically link with here ...
				}
				);

			if(Target.Platform == UnrealTargetPlatform.Win64)
			{
				PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "WiiUse/lib/Win64", "wiiuse.lib"));
				foreach(string Library in PublicAdditionalLibraries)
				{
					Console.WriteLine(Library);
				}
				//PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "WiiUse/lib/Win64", "wiiuse.dll"));
				//PublicRuntimeLibraryPaths.Add(Path.Combine(ThirdPartyPath, "WiiUse/lib/Win64"));
				PrivateIncludePaths.Add(Path.Combine(ThirdPartyPath, "WiiUse/inc"));
			}

	       /* if (UEBuildConfiguration.bBuildEditor == true)
            {
                //@TODO: Needed for the triangulation code used for sprites (but only in editor mode)
                //@TOOD: Try to move the code dependent on the triangulation code to the editor-only module
              //  PrivateDependencyModuleNames.AddRange(new string [] {"UnrealEd","ContentBrowser"});
            }*/

            PublicDelayLoadDLLs.Add("wiiuse.dll");
            //PublicDelayLoadDLLs.Add(Path.Combine(ThirdPartyPath, "WiiUse/lib/Win64", "wiiuse.dll"));
        }
	}
}
