import {
    createBrowserRouter,
    RouterProvider,
} from "react-router-dom";
import { SystemView } from "./pages/SystemView";
import { SidebarProvider, SidebarTrigger } from "./components/ui/sidebar";
import MachSidebar from "./components/MachSidebar";

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
        <main className="h-full w-full">
            <SidebarTrigger />
            <div className="p-10">
              <RouterProvider router={router} />
            </div>
        </main>
      </SidebarProvider>
    );
}