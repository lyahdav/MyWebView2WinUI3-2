#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace MyWebView2WinUI3_2;
using namespace MyWebView2WinUI3_2::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    window = make<MainWindow>();
    window.Activate();
}

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{

	{
		void (WINAPI * pfnXamlCheckProcessRequirements)();
		auto module = ::LoadLibrary(L"Microsoft.ui.xaml.dll");
		if (module)
		{
			pfnXamlCheckProcessRequirements = reinterpret_cast<decltype(pfnXamlCheckProcessRequirements)>(GetProcAddress(module, "XamlCheckProcessRequirements"));
			if (pfnXamlCheckProcessRequirements)
			{
				(*pfnXamlCheckProcessRequirements)();
			}

			// ::FreeLibrary(module); // Usually this should be uncommented, but it's commented due to https://github.com/microsoft/WindowsAppSDK/issues/3117#issuecomment-1314945705.
		}
	}


	winrt::init_apartment(winrt::apartment_type::single_threaded);
	::winrt::Microsoft::UI::Xaml::Application::Start(
		[](auto&&)
		{
			::winrt::make<::winrt::MyWebView2WinUI3_2::implementation::App>();
		});

	return 0;
}