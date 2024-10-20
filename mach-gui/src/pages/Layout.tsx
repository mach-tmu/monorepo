import {
    createBrowserRouter,
    RouterProvider,
} from "react-router-dom";
import { SystemView } from "./SystemView";

const router = createBrowserRouter([
    {
        path: "/",
        element: <SystemView />,
    },
]);

export function Layout() {
    return (
      <div className="flex flex-row">
        <div className="w-48 bg-white h-screen"></div>
        <div className="p-10">
          <RouterProvider router={router} />
        </div>
      </div>
    );
}