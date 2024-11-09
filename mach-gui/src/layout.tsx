import {
    createBrowserRouter,
    RouterProvider,
} from "react-router-dom";
import { SystemView } from "./pages/SystemView";
import { SidebarProvider, SidebarTrigger } from "./components/ui/sidebar";
import MachSidebar from "./components/MachSidebar";
import { Tooltip, TooltipContent, TooltipProvider, TooltipTrigger } from "./components/ui/tooltip";

const router = createBrowserRouter([
    {
        path: "/",
        element: <SystemView />,
    },
]);

export function Layout() {
    return (
      <SidebarProvider className="h-screen w-screen">
        <MachSidebar />
        <main className="h-full w-full relative">
            <div className="absolute top-2 left-1">
              <TooltipProvider>
                <Tooltip>
                  <TooltipTrigger asChild>
                    <SidebarTrigger/>
                  </TooltipTrigger>
                  <TooltipContent>
                    Open/Close Sidebar
                  </TooltipContent>
                </Tooltip>
              </TooltipProvider>
            </div>
            <div className="p-10 w-full h-full">
              <RouterProvider router={router} />
            </div>
        </main>
      </SidebarProvider>
    );
}